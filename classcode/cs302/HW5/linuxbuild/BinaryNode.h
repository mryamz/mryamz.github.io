#ifndef __BINARY_NODE_H__
#define __BINARY_NODE_H__


template <class T>
class BinaryNode {
private:
	T item;
	std::shared_ptr<BinaryNode<T>> left;
	std::shared_ptr<BinaryNode<T>> right;

public:
	BinaryNode();
	BinaryNode( T&);
	BinaryNode( T&, std::shared_ptr<BinaryNode<T>>, std::shared_ptr<BinaryNode<T>>);

	auto setItem( T&);
	T getItem() ;

	auto isLeaf() ;

	auto getLeft() ;
	auto getRight() ;

	auto setLeft(std::shared_ptr<BinaryNode<T>>);
	auto setRight(std::shared_ptr<BinaryNode<T>>);
};
#endif 
