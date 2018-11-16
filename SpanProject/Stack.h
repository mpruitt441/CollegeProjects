#ifndef STACK_H
#define STACK_H

#include"SLinkedList.cpp"

template <typename E>
class Stack : public SLinkedList<E>
{
public:
	Stack() : SLinkedList<E>() {}
	void push(const E& value);
	E pop();
	E top();

private:
	// SNode<E> *head;
};


#endif 