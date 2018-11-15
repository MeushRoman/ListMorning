#include "SingleLinkedList.h"

void main()
{
	SingleLinkedList<int> sll;
	sll.push_back(11);
	sll.push_front(7);
	sll.push_back(22);
	sll.push_front(17);
	sll.push_back(2);

	sll.print();

	cout << sll.getSize() << endl;
	sll.pop_front();
	
	sll.print();

	sll.pop_back();
	sll.print();

	SingleLinkedList<int> s;
	s = sll;
	s.print();
	system("pause");
}