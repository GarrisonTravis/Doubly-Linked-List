#ifndef NODE_H
#define NODE_H

template <class Type>
struct Node {
	Type val;
	Node<Type>* next;
	Node<Type>* prev;

	Node();
	Node(Type);
};

template <class Type>
Node<Type>::Node() : val(0), next(NULL), prev(NULL) {}

template <class Type>
Node<Type>::Node(Type val) {
	this->val = val;
	next = NULL;
	prev = NULL;
}

#endif
