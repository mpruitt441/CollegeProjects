#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H
#include "SNode.h"

template <typename E>
class SLinkedList {				// a singly linked list
public:
	SLinkedList();				// empty list constructor
	~SLinkedList();				// destructor
	bool empty() const;				// is list empty?
	const E& front() const;			// return front element
	void addFront(const E& e);			// add to front of list
	E removeFront();				// remove front item list
	void addBack(const E& e);
	E removeBack();
	void insert(const E& e, const E& v);
	void del(const E& e);
	E getBack();

private:
	SNode<E>* head;				// head of the list
};


#endif