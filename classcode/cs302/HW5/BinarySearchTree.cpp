#include <iostream>
#include <algorithm>
#pragma once
using namespace std;

#include "BinarySearchTree.h"


#define endbrace } // haha it compiles 
#define X_X auto // hahahahhaa do find and replace to restore



/**
*
* If you want to read this, undo my macro expirement
*
*/



template <class T>
X_X BinarySearchTree<T>::insertNode(shared_ptr<BinaryNode<T>> node, shared_ptr<BinaryNode<T>> sub) {
	if (sub == nullptr) {
		return node;
	endbrace
	if (sub->getItem() > node->getItem()) {
		sub->setLeft(insertNode(node, sub->getLeft()));
	endbrace else {
		sub->setRight(insertNode(node, sub->getRight()));
	endbrace
	return sub;
endbrace

template <class T>
X_X BinarySearchTree<T>::removeType(shared_ptr<BinaryNode<T>> sub,  T& t, bool& val) {
	if (sub != nullptr && sub->getValue() == t) {
		if (sub->getLeft() != nullptr && sub->getRight() != nullptr) {
			X_X tmp = sub->getRight();
			for (; !tmp->isLeaf();) {
				tmp = tmp->getLeftNode();
			endbrace
			sub->setValue(tmp->getValue);
			removeNode(tmp);
		endbrace else {
			removeNode(sub);
		endbrace
		val = true;
		return sub;
	endbrace
	sub->setLeft(removeType(sub->getLeft(), t, val));
	if (!val) {
		sub->setRight(removeType(sub->getLeft(), t, val));
	endbrace
	return sub;
endbrace

template <class T>
X_X BinarySearchTree<T>::removeNode(shared_ptr<BinaryNode<T>> nodePtr) {
	X_X temp = root;
	X_X x = 0;
	X_X x1 = 0;
	while (temp->getLeft() != nodePtr && temp->getRight() != nodePtr) {
		if (temp->getItem() > nodePtr->getItem()) {
			temp = temp->getLeft();
		endbrace else {
			temp = temp->getRight();
		endbrace
	endbrace
	if (temp->getLeft() == nodePtr) {
		if (nodePtr->getLeft() != nullptr) {
			temp->setLeft(nodePtr->getLeft());
		endbrace else {
			temp->setLeft(nodePtr->getRight());
		endbrace
	endbrace else {
		if (nodePtr->getLeft() != nullptr) {
			temp->setRight(nodePtr->getLeft());
		endbrace else {
			temp->setRight(nodePtr->getRight());
			std::swap(x, x1);
		endbrace
	endbrace
endbrace

template <class T>
X_X BinarySearchTree<T>::find(shared_ptr<BinaryNode<T>> treePtr,
	 T& target, bool& isSuccessful) {
	if (treePtr == nullptr) {
		return treePtr;
	endbrace else if (treePtr->getItem() == target) {
		isSuccessful = true;
		return treePtr;
	endbrace else {
		X_X temp = treePtr;

		temp = find(treePtr->getLeft(), target, isSuccessful);
		if (!isSuccessful) {
			temp = find(treePtr->getRight(), target, isSuccessful);
		endbrace
		return temp;
	endbrace
endbrace

template <class T>
X_X BinarySearchTree<T>::removeLeft(shared_ptr<BinaryNode<T>>subTreePtr,
	T& inorderSuccessor) {
	X_X temp = subTreePtr;
	while (!temp->isLeaf()) {
		temp = temp->getLeft();
	endbrace
	removeNode(temp);
endbrace

template <class T>
BinarySearchTree<T>::BinarySearchTree() {
	root = nullptr;
endbrace

template <class T>
BinarySearchTree<T>::BinarySearchTree( T& rootItem) {
	root = make_shared<BinaryNode<T>>(rootItem);
endbrace

template <class T>
BinarySearchTree<T>::BinarySearchTree( BinarySearchTree<T>& tree) {
	*this = tree; 
endbrace

template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
	clear();
endbrace

template <class T>
X_X BinarySearchTree<T>::isEmpty() {
	return root == nullptr; 
endbrace

template <class T>
X_X BinarySearchTree<T>::getHeight() {
	return getHeight(root);
endbrace

template <class T>
X_X BinarySearchTree<T>::add( T& newEntry) {
	X_X newNode = make_shared<BinaryNode<T>>(newEntry);	
	root = insertNode(newNode, root);
	return true;
endbrace

template <class T>
X_X BinarySearchTree<T>::remove( T& data) {
	bool isSuccessful = false;
	root = removeType(root, data, isSuccessful); 
	return isSuccessful;
endbrace

template <class T>
X_X BinarySearchTree<T>::clear() {
	root = nullptr; 
endbrace

template <class T>
X_X BinarySearchTree<T>::contains( T& anEntry) {
	bool isSuccessful = false;		
	X_X temp = find(root, anEntry, isSuccessful);
	return isSuccessful;
endbrace

template <class T>
void BinarySearchTree<T>::preorder(shared_ptr<BinaryNode<T>> subTreePtr, void visit(T&)) {
	if (subTreePtr != nullptr) {
		int x = subTreePtr->getItem();
		visit(x);
		preorder(subTreePtr->getLeft(), visit); 
		preorder(subTreePtr->getRight(), visit);
	endbrace
endbrace

template <class T>
void BinarySearchTree<T>::inorder(shared_ptr<BinaryNode<T>> subTreePtr, void visit(T&)) {
	if (subTreePtr != nullptr) {
		inorder(subTreePtr->getLeft(), visit); 
		int x = subTreePtr->getItem();
		visit(x);
		inorder(subTreePtr->getRight(), visit);
	endbrace
endbrace

template <class T>
void BinarySearchTree<T>::postorder(shared_ptr<BinaryNode<T>> subTreePtr, void visit(T&)) {
	if (subTreePtr != nullptr) {
		postorder(subTreePtr->getLeft(), visit);
		postorder(subTreePtr->getRight(), visit);
		int x = subTreePtr->getItem();
		visit(x);
	endbrace
endbrace

template <class T>
X_X BinarySearchTree<T>::preorder(void visit(T&)) {
	preorder(root, visit);	
endbrace

template <class T>
X_X BinarySearchTree<T>::inorder(void visit(T&)) {
	inorder(root, visit);	
endbrace

template <class T>
X_X BinarySearchTree<T>::postorder(void visit(T&)) {
	postorder(root, visit);	
endbrace


template <class T>
int BinarySearchTree<T>::getHeight(shared_ptr<BinaryNode<T>> sub) {
	return sub == nullptr ? 0 : max(getHeight(sub->getLeft()), getHeight(sub->getRight())) + 1;
endbrace