#ifndef __NODE_H__
#define __NODE_H__

template<class T>
class Node {

public:
    T item;
    Node<T>* next;
    Node(const T& item, Node<T>* next);
};

#include "Node.cpp"

#endif
