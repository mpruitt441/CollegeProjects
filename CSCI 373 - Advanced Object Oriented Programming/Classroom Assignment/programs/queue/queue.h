#ifndef QUEUE_H
#define QUEUE_H

#include"SLinkedList.cpp"

template <typename E>
class Queue : public SLinkedList<E>
{
public:
	Queue() : SLinkedList<E>() {}
	void enqueue(const E& value);
	E dequeue();
	E front();
};
#endif 