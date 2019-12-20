#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

//Default Constructor
template <class Type>
DoublyLinkedList<Type>::DoublyLinkedList() : head(NULL), tail(NULL) {}

//Constructor that will create a list with one node
template <class Type>
DoublyLinkedList<Type>::DoublyLinkedList(Type val) {
	head = new Node<Type>(val);
	tail = head;
}

//Constructor that will create a list to match the given array
template <class Type>
DoublyLinkedList<Type>::DoublyLinkedList(Type arr[], int size) {

	Node<Type>* newNode = new Node<Type>;
	newNode->val = arr[size - 1];
	head = newNode;
	tail = newNode;

	for (int i = size - 2; i >= 0; i--) {
		newNode = new Node<Type>;
		newNode->val = arr[i];
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
}

//Outputs the doubly linked list
template <class Type>
void DoublyLinkedList<Type>::print() {
	Node<Type>* current = head;

	cout << "List = ";
	while (current) {
		cout << current->val << " ";
		current = current->next;
	}
	cout << endl;
}

//Outputs the double linked list in reverse
template <class Type>
void DoublyLinkedList<Type>::printReverse() {
	Node<Type>* current = tail;

	cout << "List in Reverse = ";
	while (current) {
		cout << current->val << " ";
		current = current->prev;
	}
	cout << endl;
}
