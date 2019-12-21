#include <iostream>
#include <stdexcept>
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

	//Loop that assigns each element in the array to the list
	//And links the pointers, next and prev
	for (int i = size - 2; i >= 0; i--) {
		newNode = new Node<Type>;
		newNode->val = arr[i];
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
}

//Inserts a node at the front of the list
//Post: The list will contain a new node at the front
//O(1)
template <class Type>
void DoublyLinkedList<Type>::insertFront(Type val) {
	Node<Type>* newNode = new Node<Type>(val);

	//If the list is empty
	if (head == NULL) {
		head = newNode;
		tail = newNode;
	}
	//If the list has at least 1 node
	else {
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
}

//Inserts a node at the back of the list
//Post: The list will contain a new node at the back
//O(1)
template <class Type>
void DoublyLinkedList<Type>::insertBack(Type val) {
	Node<Type>* newNode = new Node<Type>(val);

	if (head == NULL) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}

//Inserts the given value at the given index
//The current value at that index is pushed back (+1)
//Throws an exception if index is out of range
//Post: The List will contain the new value at the given index
template <class Type>
void DoublyLinkedList<Type>::insertAt(Type val, int index) {
	Node<Type>* current = head;
	int i = 0;

	while (current && i < index) {
		current = current->next;
		i++;
	}
	
	if(current == NULL)
		throw std::runtime_error("The index is out of range.");
	else {
		Node<Type>* newNode = new Node<Type>(val);

		//Insert the node in the middle of the list
		if (current != head) {
			current->prev->next = newNode;
			newNode->prev = current->prev;
			newNode->next = current;
			current->prev = newNode;
		}
		//Insert the node at index 0
		else if (current == head) {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	}
}

//Replaces the value at the given index with the value passed to the function
//If index is out of range, throw a runtime exception
//Post: List will now contain the new value at the given index
template <class Type>
void DoublyLinkedList<Type>::replace(Type val, int index) {
	Node<Type>* current = head;
	int i = 0;

	while (current && i < index) {
		current = current->next;
		i++;
	}

	//Replace the value
	if(current != NULL)
		current->val = val;
	else 
		throw runtime_error("The index is out of range.");
}

//Deletes every instance of the given value
//Post: List will no longer contain any of the given values
template <class Type>
void DoublyLinkedList<Type>::deleteValue(Type val) {
	if (head == NULL)
		return;

	Node<Type>* current = head;
	Node<Type>* temp;

	while (current) {
		if (current->val == val) {
			//Deletes a node in the middle of the list
			if (current->prev != NULL && current->next != NULL) {
				current->prev->next = current->next;
				current->next->prev = current->prev;
				temp = current->next;
				delete current;
				current = temp;
			}
			//Deletes a node at end of the list
			else if (current->prev != NULL && current->next == NULL) {
				tail = current->prev;
				tail->next = NULL;
				delete current;
				current = NULL;
			}
			//Deletes a node at the beginning of the list
			else if (current->prev == NULL && current->next != NULL) {
				head = current->next;
				head->prev = NULL;
				delete current;
				current = head;
			}
			//Deletes the only node in the list
			else if (current->prev == NULL && current->next == NULL) {
				delete current;
				head = NULL;
				tail = NULL;
				current = NULL;
			}
		}
		else {
			current = current->next;
		}
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

//Deletes every node in the list
//Post: Empty list with head and tail pointing to NULL
template <class Type>
void DoublyLinkedList<Type>::clear() {
	Node<Type>* current = head;

	while (current) {
		head = current->next;
		delete current;
		current = head;
	}
}
