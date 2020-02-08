
#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <iostream>
#include "Node.h"

template <class T>
class LinkedList {

private:
	Node<T>* pfirst;
	Node<T>* plast;
	

	int size = 0;

public:
	LinkedList();

public:
	void add(const T& item);
	void add(const T& item, int index);
	void remove(int index);
	void clear();
	int getSize();
	T get(int index);
	Node<T>* getNode(int index);
	std::string toString();




};




#include "LinkedList.cpp"
#endif // __LINKED_LIST__
