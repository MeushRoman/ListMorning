#pragma once
#include<iostream>

using namespace std;

template<class T>
struct elem {
	T obj;
	elem<T> *next;
};

template<class T>
class SingleLinkedList
{
	elem<T>*head;
	int size;
	elem<T>*cursor;

public:
	SingleLinkedList();
	void push_back(const T&obj);
	void push_front(const T&obj);

	void insert(const T&obj, size_t position);

	void pop_back();
	void pop_front();

	void erase(size_t position);

	void print();

	int getSize()const { return size; }

	SingleLinkedList(const T&obj);
	T&operator=(const T&obj);

	SingleLinkedList(const T&&obj);
	T&operator=(T&&obj);

	~SingleLinkedList();
};

template<class T>
SingleLinkedList<T>::SingleLinkedList()
{
	head = nullptr;
	size = 0;
}

template<class T>
void SingleLinkedList<T>::push_back(const T & obj)
{
	elem<T>*newElem = new elem<T>;
	newElem->obj = obj;
	newElem->next = nullptr;
	if (head == nullptr) {
		head = newElem;
		size = 1;
		return;
	}
	cursor = head;
	while (cursor->next != nullptr)
		cursor = cursor->next;

	cursor->next = newElem;
	this->size++;
}

template<class T>
void SingleLinkedList<T>::push_front(const T & obj)
{
	elem<T>*newElem = new elem<T>;
	newElem->obj = obj;
	newElem->next = head;
	head = newElem;
	this->size++;
}

template<class T>
void SingleLinkedList<T>::insert(const T & obj, size_t position)
{
	if (position > size || position < 0)
		return;
	if (position == 0) {
		push_front(obj);
		return;
	}
	if (position == size) {
		push_back(obj);
		return;
	}

	elem<T>*newElem = new elem<T>;
	newElem->obj = obj;
	cursor = head;
	for (size_t i = 0; i < position - 1; i++)
	{
		cursor = cursor->next;
	}
	newElem->next = cursor->next;
	cursor->next = newElem;
	size++;
}
template<class T>
void SingleLinkedList<T>::pop_back()
{
	if (size > 0) {
		if (size == 1) {
			delete head;
			size = 0;
			head = nullptr;
			return;
		}
		cursor = head;
		for (size_t i = 0; i < size - 2; i++)
		{
			cursor = cursor->next;
		}
		delete cursor->next;
		cursor->next = nullptr;
		size--;
	}
}
template<class T>
void SingleLinkedList<T>::pop_front()
{
	if (size == 0)
		return;
	if (size == 1) {
		delete head;
		head = nullptr;
		size = 0;
		return;
	}
	cursor = head->next;
	delete head;
	head = cursor;
	size--;
}

template<class T>
void SingleLinkedList<T>::erase(size_t position)
{
	if (position == 0)
	{
		pop_front();
	}
	else
	{
		elem<T> *prev = this->head;
		for (int i = 0; i < position - 1; i++)
		{
			prev = prev->next;
		}
		elem<T> *del = prev->next;
		prev->next = del->next;
		delete del;
		size--;
	}
}

template<class T>
void SingleLinkedList<T>::print()
{
	cursor = head;
	while (cursor != nullptr)
	{
		cout << cursor->obj << " ";
		cursor = cursor->next;
	}
	cout << endl;
}

template<class T>
SingleLinkedList<T>::SingleLinkedList(const T & obj)
{
	head = nullptr;
	cursor = obj.head;
	while (cursor != nullptr)
	{
		push_back(cursor->obj);
		cursor = cursor->next;
	}
	this->size = obj.size;
}

template<class T>
T & SingleLinkedList<T>::operator=(const T & obj)
{
	if (this = &obj) return *this;
	this->~SingleLinkedList();
	cursor = obj.head;
	while (cursor != nullptr)
	{
		push_back(cursor->obj);
		cursor = cursor->next;
	}
	this->size = obj.size;
	return *this;
}

template<class T>
SingleLinkedList<T>::SingleLinkedList(const T && obj)
{
	swap(this->head, obj.head);
	swap(this->size, obj.size);
}

template<class T>
T & SingleLinkedList<T>::operator=(T && obj)
{

	swap(this->head, obj.head);
	swap(this->size, obj.size);
	return *this;
}

template<class T>
SingleLinkedList<T>::~SingleLinkedList()
{
	while (cursor != nullptr)
	{
		elem <T> *tmp = cursor->next;
		delete cursor;
		cursor = tmp;
	}
}

