#include "queue.h"


template <typename E>
void Queue<E>::enqueue(const E& value) {
	Queue<E>::addFront(value);
}

template <typename E>
E Queue<E>::dequeue() {
	return Queue<E>::removeFront();
}

template <typename E>
E Queue<E>::front() {
	return Queue<E>::front();

}