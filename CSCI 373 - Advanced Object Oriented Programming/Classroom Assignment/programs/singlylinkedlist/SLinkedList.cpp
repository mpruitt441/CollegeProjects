#include "SLinkedList.h"




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
	SNode<E> *temp;
	temp = head;
	SNode<E> *prev;
	prev = NULL;
	if (temp->next == NULL) {
		std::cout << "Deleting head\n";
		return removeFront();
	}
	else {

		std::cout << "Head Element: " << temp->elem << std::endl;
		std::cout << "Please let us get in the loop\n" << std::endl;
		while (temp->next != NULL) {
			std::cout << "Inside the loop:  " << prev << std::endl;
			prev = temp;
			std::cout << "Prev value is " << prev->elem << std::endl;
			temp = temp->next;
		}
		prev->next = NULL;
		delete temp;
		temp = NULL;
		return prev->elem;
	}
}

template <typename E>
void SLinkedList<E>::insertion(const E& value) {
	if (empty()) {
		// if empty, add a head
		cout << "adding a head..\n";
		SNode<E> *v = new SNode<E>;
		v->elem = value;
		v->next = NULL;
		head = v;
	}
	else if (head->next == NULL) {
		// if theres only a HEAD in the list, compare the two
		cout << "inserting.. " << value << endl;
		if (value > head->elem) {
			// if the head is smaller, then the new node goes on top
			SNode<E> *m = new SNode<E>;
			m->elem = value;
			head->next = m;
			m->next = NULL;
			cout << "only one head in the list. head-> next is " << head->next << endl;
		}
		else {
			// if the head is bigger, then the new node becomes the new head
			cout << "Head is bigger... adding a new node and setting it to head...";
			SNode<E> *n = new SNode<E>;
			SNode<E> *old = head;
			n->elem = value;
			n->next = head;
			head = n;
			old->next = NULL;
		}
	}
	else {
		cout << "inserting with the condition of 2 or more nodes\n";
		SNode<E> *prev, *low, *max;
		low = NULL;
		max = NULL;
		SNode<E> *temp;
		SNode<E> *v = new SNode<E>;
		v->elem = value;
		temp = head;
		prev = NULL;
		// temp over the while loop
		while (temp->next != NULL) {
			prev = temp;
			
			if (prev != NULL && prev->elem <= value) {
				low = prev;
			}
			temp = temp->next;
			if (temp != NULL && temp->elem >= value)
				max = temp;
		} // end while statement

		if (max == head) {
			cout << "Creating a new head " << v->elem << " before " << head->elem << endl;
			v->next = max;
			head = v;
		}
		else if (max == NULL){
			cout << "Adding " << v->elem << " at the end after " << prev->elem << endl;
			prev->next = v;
			v->next = max;
			cout << "the last value is " << v->elem << " and the next value is " << v->next << endl;
			cout << "prev is " << prev->elem << " and points to " << prev->next << endl;
		}
		else {
			cout << "inserting " << v->elem << " between " << low->elem << " and " << max->elem << endl;
			v->next = max;
			low->next = v;
		}
	} // end this big else section				
}	

template<typename E>
void SLinkedList<E>::del(const E& value) {
	if (head->next == NULL) {
		head = NULL;
	}
	else {
		SNode<E> *temp, *prev;
		prev = NULL;
		temp = head;
		while (temp->next != NULL) {
			prev = temp;
			temp = temp->next;
			if (value == temp->elem) {
				prev->next = temp->next;
				delete temp;
				temp = prev->next;
			}
		}
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

template <typename E>
void SLinkedList<E>::printer(std::ostream& out) {
	SNode<E> *temp = head;
	while (temp->next != NULL) {
		out << "Printing list... " << temp->elem << endl;
		temp = temp->next;
		cout << temp->next << endl;
	}
}