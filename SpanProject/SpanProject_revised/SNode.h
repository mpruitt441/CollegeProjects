#ifndef SNODE_H
#define SNODE_H


template <typename E>
class SNode {
public:
	E elem;
	SNode<E>* next;

};

#endif