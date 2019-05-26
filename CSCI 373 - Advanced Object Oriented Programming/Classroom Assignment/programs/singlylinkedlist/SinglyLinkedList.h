#ifndef LIST_H
#define LIST_H

#include"SLinkedList.cpp"

template <typename E>
class SinglyLinkedList : public SLinkedList<E>
{
public:
	SinglyLinkedList() : SLinkedList<E>() {}
	void insert(const E& value);
	void remove(const E& value);
	void print(std::ostream& out);

};



#endif 