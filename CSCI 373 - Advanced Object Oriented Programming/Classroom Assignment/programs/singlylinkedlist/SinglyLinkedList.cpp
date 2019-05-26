#include "SinglyLinkedList.h"

template <typename E>
void SinglyLinkedList<E>::insert(const E& value) {
	SinglyLinkedList<E>::insertion(value);
}


template <typename E>
void SinglyLinkedList<E>::remove(const E& value) {
	SinglyLinkedList<E>::del(value);
}

template <typename E>
void SinglyLinkedList<E>::print(std::ostream& out){
	
	SinglyLinkedList<E>::printer(out);

}