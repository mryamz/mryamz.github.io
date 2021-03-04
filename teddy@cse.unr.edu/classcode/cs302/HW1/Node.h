#ifndef __NODE__
#define __NODE__

template <class T>
class Node {
public:
	T item;
	Node<T>* next;
};

#include "Node.cpp"
#endif // __NODE__


