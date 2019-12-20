#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Node.h"

template <class Type>
class DoublyLinkedList {
private:
	Node<Type>* head;
	Node<Type>* tail;
public:

	DoublyLinkedList();
	DoublyLinkedList(Type);
	DoublyLinkedList(Type[], int);

	void print();
	void printReverse();
};

#endif
