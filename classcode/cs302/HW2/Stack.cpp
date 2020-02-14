#include "Stack.h"
#include "Node.h"
#include <iostream>

#ifndef __STACK_CPP__
#define __STACK_CPP__

template<class T>
Stack<T>::Stack()
{
	maxSize = 0;

}

template<class T>
Stack<T>::Stack(unsigned long maxSize)
{
	this->maxSize = maxSize;
}

template<class T>
Stack<T>::Stack(Stack& toCopy)
{
	this->size = toCopy.size;
	this->maxSize = toCopy.maxSize;

	for (int i = 0; i < toCopy.size; i++) {
		
	}

}

template<class T>
Stack<T>& Stack<T>::operator=(Stack& toCopy)
{
	// TODO: insert return statement here
}

template<class T>
Stack<T>::~Stack()
{
	clear();
}

template<class T>
void Stack<T>::push(const T& t)
{
	if (!isFull()) {
		top = new Node<T>(t, top);
		size++;
	}
}

template<class T>
void Stack<T>::pop()
{
	if (!isEmpty()) {
		Node<T>* next = top->next;
		delete top;
		top = next;
		size--;
	}
}

template<class T>
T Stack<T>::peek()
{

	if (!isEmpty()) {
		return top->item;
	}

	std::cout << "Runtime exception should be thrown" << std::endl;
	return T();
}

template<class T>
void Stack<T>::clear()
{
	while (!isEmpty()) {
		pop();
	}
}

template<class T>
bool Stack<T>::isEmpty() const
{
	return this->size == 0;
}

template<class T>
bool Stack<T>::isFull() const
{
	return maxSize == 0 ? false : size - 1 > maxSize ? true : false;
}

template<class T>
std::string Stack<T>::toString()
{
	std::string str;

	str += "{";

	Node<T>* curr = top;
	for (int i = 0; i < size; i++) {
		str += curr->item;
		str += " ";
		str += (i == size - 1 ? "" : ", ");

		curr = curr->next;
	}

	str += "}";


	return str;
}

#endif