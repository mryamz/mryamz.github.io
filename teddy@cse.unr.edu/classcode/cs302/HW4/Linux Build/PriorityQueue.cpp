#ifndef __PRIO_Q_CPP__
#define __PRIO_Q_CPP__

#define null nullptr

#include <iostream>
#include "PriorityQueue.h"


template<class T>
PriorityQueue<T>::PriorityQueue()
{
	this->front = null;
}

template<class T>
void PriorityQueue<T>::insert(T t, int prio)
{
    Node<T>* new_info;
    new_info = new Node<T>(t, prio);


    Node<T>* iterator;

  
    
    if (isEmpty()) {
        new_info->next = front;
        front = new_info;
        return;
    }


    bool hasPriority = prio < front->priority;
    if (hasPriority) {
        new_info->next = front;
        front = new_info;
        return;
    }

    iterator = front;
    while (iterator->next != null && iterator->next->priority < prio)
        iterator = iterator->next;

    new_info->next = iterator->next;
    iterator->next = new_info;
}

template<class T>
T PriorityQueue<T>::getPriority()
{
    return front->priority;
}

template<class T>
T PriorityQueue<T>::getValue()
{
    return front->t;
}

template<class T>
T PriorityQueue<T>::remove()
{
    Node<T>* value;

    if (isEmpty()) 
        return -1;

    value = front;
    T ret = value->t;

    front = front->next;
    delete value;
    return ret;
}

template<class T>
bool PriorityQueue<T>::isEmpty()
{
    return front == null;
}

template<class T>
void PriorityQueue<T>::debugIO()
{
    using namespace std;
     
        Node<T>* curr;
        curr = front;

        if (isEmpty()) {
            cout << "is empty\n";
            return;
        }

        cout << "Debug Priority Queue:\n";
        cout << "Arrival Time       Departure Time\n";
        while (curr != null)
        {
           cout << curr->priority << "                  " << curr->t << endl;
           curr = curr->next;
    }
}

#endif