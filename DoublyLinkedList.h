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

	void insertFront(Type);
	void insertBack(Type);
	void insertAt(Type, int);
	void replace(Type, int);
	void deleteValue(Type);

	void print();
	void printReverse();

	void clear();
};

#endif
