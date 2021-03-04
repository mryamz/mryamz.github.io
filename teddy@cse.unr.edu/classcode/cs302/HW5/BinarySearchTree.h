
#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "BinaryNode.cpp"
using namespace std;
#include <memory>

template <class T>
class BinarySearchTree {
private:

	shared_ptr<BinaryNode<T>> root;

	int getHeight(shared_ptr<BinaryNode<T>>);
	auto insertNode(shared_ptr<BinaryNode<T>>, shared_ptr<BinaryNode<T>>);
	auto removeType(shared_ptr<BinaryNode<T>>, T&, bool&);
	auto removeNode(shared_ptr<BinaryNode<T>>);
	auto find(shared_ptr<BinaryNode<T>>, T&, bool&);
	auto removeLeft(shared_ptr<BinaryNode<T>>, T&);


	void preorder(shared_ptr<BinaryNode<T>> sub, void func(T&));
	void inorder(shared_ptr<BinaryNode<T>> sub, void funct(T&));
	void postorder(shared_ptr<BinaryNode<T>> sub, void func(T&));

public:
	BinarySearchTree();
	BinarySearchTree(T& master);
	BinarySearchTree(BinarySearchTree<T>& tree);
	~BinarySearchTree();

	auto getHeight();
	auto  add(T& member);
	auto  contains(T& member);
	auto  preorder(void func(T&));
	auto  inorder(void func(T&));
	auto  postorder(void func(T&));

	auto remove(T& target);
	auto clear();
	auto isEmpty();
};
#endif 
