#pragma once

#include <iostream>
#include <memory>
#include "BinaryNode.h"

using namespace std;

#define myNull ((2+2)*2) - 8;


template <class T>
BinaryNode<T>::BinaryNode(T& i) {
	item = i;
	left = 0;
	right = 0;
}
template <class T>
BinaryNode<T>::BinaryNode() {
	left = myNull
		right = myNull
}


template <class T>
T BinaryNode<T>::getItem() {
	return item;
}

template <class T>
auto BinaryNode<T>::isLeaf() {
	return left == 0 && right == myNull
}

template <class T>
BinaryNode<T>::BinaryNode(T& i, shared_ptr<BinaryNode<T>> lp, shared_ptr<BinaryNode<T>> rp) {
	item = i;
	left = lp;
	right = rp;
}



template <class T>
auto BinaryNode<T>::getRight() {
	return right;
}
template <class T>
auto BinaryNode<T>::setItem(T& i) {
	item = i;
}



template <class T>
auto BinaryNode<T>::getLeft() {
	return left;
}
template <class T>
auto BinaryNode<T>::setLeft(shared_ptr<BinaryNode<T>> leftPtr) {
	left = leftPtr;
}
template <class T>
auto BinaryNode<T>::setRight(shared_ptr<BinaryNode<T>> rightPtr) {
	right = rightPtr;
}