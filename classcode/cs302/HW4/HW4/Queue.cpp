

#ifndef __QUEUE_CPP__
#define __QUEUE_CPP__



#include "Queue.h"

#define null nullptr

template<class T>
Queue<T>::Queue()
{
	front = back = null;
}

template<class T>
void Queue<T>::enque(T t)
{

    Node<T>* value = new Node<T>(t);

    bool isEmpty = back == null;
    if (isEmpty) {
        front = back = value;
    }
    else {

        back->next = value;
        back = value;
    }
}

template<class T>
void Queue<T>::deque()
{
    bool isEmpty = back == null;

    if (isEmpty)
        return;

    Node<T>* value = front;
    front = front->next;

    if (front == null)
        back = null;


    delete (value);
}

#endif // !__QUEUE_CPP__