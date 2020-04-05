#pragma once


template <class T>
class Node {
public:
    T t;
    Node* next;
    Node();

    Node(T t) {
        this->t = t;
        next = nullptr;
    }
};