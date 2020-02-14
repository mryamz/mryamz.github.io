#include "Node.h"
#ifndef __NODE_CPP__
#define __NODE_CPP__

template<class T>
Node<T>::Node(const T& item, Node<T>* next)
{

	this->item = item;
	this->next = next;

}

#endif
