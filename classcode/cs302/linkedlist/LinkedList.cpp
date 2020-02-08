#include "LinkedList.h"
#include <iostream>
#include <string>

#ifndef __LINKED_LIST_CPP__
#define __LINKED_LIST_CPP__

template<class T>
LinkedList<T>::LinkedList()
{

}

template<class T>
void LinkedList<T>::add(const T& item)
{
	// create node and pass item to it
	Node<T>* newNode = new Node<T>();
	newNode->item = item;

	newNode->next = pfirst;
	pfirst = newNode;

	if (!plast)
		plast = pfirst;

	size++;
}

template<class T>
void LinkedList<T>::add(const T & item, int index)
{
	if (index > size)
		return;

	if (size == 0) {
		add(item);
		return;
	}

	// create node and pass item to it
	Node<T>* newNode = new Node<T>();
	newNode->item = item;



	Node<T>* localHead = getNode(index);


	newNode->next = localHead;
	localHead = newNode;

}

template<class T>
void LinkedList<T>::remove(int index)
{
	Node<T>* toRemove = getNode(index);

	if (index == 0) {
		pfirst = getNode(1);
		delete toRemove;
		return;
	}

	if (index == size - 1) {
		Node<T>* before_tail = getNode(size - 2);
		before_tail->next = nullptr;
		plast = before_tail;
		delete toRemove;
		return;
	}

	Node<T>* before = getNode(index - 1);
	Node<T>* after = getNode(index + 1);

	std::cout << "1) " << before << " " << after << std::endl;
	before->next = after;
	std::cout << "2) " << before << " " << after << std::endl;

	delete toRemove;


	size--;
	
}

template<class T>
void LinkedList<T>::clear()
{

	for (int i = 0; i < size; i++) {
		delete getNode(i);
	}

	size = 0;
}

template<class T>
int LinkedList<T>::getSize()
{
	return size;
}

template<class T>
T LinkedList<T>::get(int index)
{
	Node<T>* node = getNode(index);
	return node->item;
}

template<class T>
Node<T>* LinkedList<T>::getNode(int index)
{
	if (index > size)
		return 0;

	index = (size - 1) - index;

	Node<T>* current = pfirst;

	for (int i = 0; i < index; i++) {
		current = current->next;
	}

	return current;
}

template<class T>
std::string LinkedList<T>::toString()
{
	std::string list_str;
	list_str += "{";
	for (int i = 0; i < size; i++) {
		list_str += std::to_string(get(i));
		list_str += i == size - 1 ? "" : ",";
		
	}
	list_str += "}";

	return list_str;
}

#endif