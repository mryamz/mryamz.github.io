#include<algorithm>
#include <iostream>
#include <fstream>
#include "BinarySearchTree.cpp"


#define printInt(x) std::cout << x << "_";  
 
void printeger(int& x) {
	printInt(x)   
}               

int main() { 
	using namespace std; 

	ifstream input;
	input.open("data.txt"); 

	BinarySearchTree<int> tree;
	
	while (!input.eof()) {
		int currentToken;
		input >> currentToken;
		tree.add(currentToken);
	}

	input.close();

	std::cout << "\n\n - postorder - " << endl;
	tree.postorder(printeger);

	std::cout << "\n\n - preorder - " << endl; 
	tree.preorder(printeger);

	std::cout << "\n\n - inorder - " << endl;
	tree.inorder(printeger); 

	std::cout << "getHeight(): " << tree.getHeight() << endl;
}