#include "Node.h"
#include <string>
#include <iostream>

#ifndef __STACK_H__
#define __STACK_H__

template<class T>
class Stack {

private:
	Node<T>* top;
	unsigned long size = 0;
	unsigned long maxSize = 0;

public:
	Stack();
	Stack(unsigned long maxSize);
	Stack(Stack& toCopy);

	Stack<T>& operator=(Stack& toCopy);

	~Stack();

	void push(const T& t);

	void pop();

	T peek();

	void clear();

	bool isEmpty() const;

	bool isFull() const;

	std::string toString();

};

#include "Stack.cpp"
#endif // DEBUG


