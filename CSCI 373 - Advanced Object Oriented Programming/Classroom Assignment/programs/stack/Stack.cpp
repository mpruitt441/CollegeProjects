#include "Stack.h"


template <typename E>
void Stack<E>::push(const E& value) {
	
		Stack<E>::addBack(value);
}

template <typename E>
E Stack<E>::pop() {

	return Stack<E>::removeBack();

}
template <typename E>
E Stack<E>::top() {
	return Stack<E>::getBack();
}
