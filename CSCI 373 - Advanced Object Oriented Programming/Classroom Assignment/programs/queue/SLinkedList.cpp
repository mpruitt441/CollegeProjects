#include "SLinkedList.h"
#include <cstdlib>

template <typename E>
SLinkedList<E>::SLinkedList()				// constructor
	: head(NULL) { }

template <typename E>
bool SLinkedList<E>::empty() const			// is list empty?
{
	return head == NULL;
}

template <typename E>
const E& SLinkedList<E>::front() const		// return front element
{
	return head->elem;
}

template <typename E>
SLinkedList<E>::~SLinkedList()			// destructor
{
	while (!empty()) removeFront();
}


template <typename E>
void SLinkedList<E>::addFront(const E& e) {		// add to front of list
	SNode<E>* v = new SNode<E>;				// create new node
	v->elem = e;					// store data
	v->next = head;					// head now follows v
	head = v;
	std::cout << "Pushed: " << v->elem << std::endl;
	// v is now the head
}


template <typename E>
E SLinkedList<E>::removeFront() {			// remove front item
	SNode<E>* old = head;				// save current head
	E ret = head->elem;
	head = old->next;					// skip over old head
	delete old;						// delete the old head
	return ret;
}

template <typename E>
void SLinkedList<E>::addBack(const E& e) {		// add to front of list
	if (empty()) {
		addFront(e);
		std::cout << "was empty\n";
		head->next = NULL;
	}
	else {
		SNode<E> *v = new SNode<E>;
		SNode<E> *temp = head;
		v->elem = e;
		while (temp->next != NULL) {
			std::cout << "At: " << temp->elem << std::endl;
			temp = temp->next;


		}
		temp->next = v;
		v->next = NULL;
		std::cout << "Pushed: " << v->elem << std::endl;
	}
}

// remove back
template <typename E>
E SLinkedList<E>::removeBack() {

	if (head->next = NULL) {
		return removeFront();
	}
	else {
		SNode<E> *prev = NULL;
		SNode<E> *temp;
		temp = head;
		std::cout << "Head Element: " << temp->elem << std::endl;

		std::cout << "Please let us get in the loop\n" << std::endl;
		while (temp->next != NULL) {
			std::cout << "I'm at value: " << prev << std::endl;
			prev = temp->next;
			temp = temp->next;
		}
		prev->next = NULL;
		delete temp;
		temp = NULL;
		return prev->elem;
	}
}

template <typename E>
void SLinkedList<E>::insert(const E& e, const E& insertafter) {
	if (head->next = NULL) {
		addFront(0);
		std::cout << "Empty list. Adding 0...\n";
	}

	SNode<E> *v = new SNode<E>;		// create new node
	SNode<E> *temp = head;
	SNode<E> *prev;

	while (insertafter != prev) {
		prev = temp;
		temp = temp->next;
	}
	v->elem = e;
	prev->v;
	v->temp;

}
template<typename E>
void SLinkedList<E>::del(const E& e) {
	if (head->next = NULL) {
		addFront(0);
		std::cout << "Empty list. Adding 0...\n";
	}
	SNode<E> *temp = head;
	SNode<E> *prev;

	while (temp->next != NULL && prev != e) {
		prev = temp;
		temp = temp->next;

	}

	if (prev = e)
	{
		std::cout << "Value found!\n";
		delete prev;
	}
	else if (prev != e)
	{
		std::cout << "Value not found!\n";


	}
}

template <typename E>
E SLinkedList<E>::getBack() {
	SNode<E> *temp = head;
	while (temp->next != NULL) {
		temp = temp->next;

	}

	return temp->elem;
}
