#pragma once
#define null nullptr


template <class T>
class Node {
public:
    T t;
    Node* next;
    int priority;

    Node() {

    }

    Node(T t) {
        this->t = t;
        next = nullptr;
    }

    Node(T t, int priority) {
        this->t = t;
        next = nullptr;
        this->priority = priority;
    }
};