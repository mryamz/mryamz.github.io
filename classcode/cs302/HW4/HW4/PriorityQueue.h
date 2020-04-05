#ifndef __PRIO_Q_H__
#define __PRIO_Q_H__
#include "Node.h"

template <class T>
class PriorityQueue
{

public:
	Node<T>* front;

	PriorityQueue();

	void insert(T t, int prio);

	T remove();

	bool isEmpty();

	void debugIO();

};



#include "PriorityQueue.cpp"

#endif


