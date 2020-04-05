#ifndef __QUEUE_H__
#define __QUEUE_H__


#include "Node.h"

template <class T>
class Queue
{

public:
	Node<T>* front,* back;

	Queue();

	void enque(T t);

	void deque();

};

#include "Queue.cpp"

#endif // !__QUEUE_H__