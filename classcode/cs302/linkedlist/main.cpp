#include <iostream>
#include <string>
#include <stdlib.h>    
#include "LinkedList.h"

void menu() {
	bool isRunning = true;
	LinkedList<int> list;
	list.add(5);
	list.add(6);
	list.add(2);
	list.add(9);
	list.add(5);
	list.add(1);
	list.add(4);
	list.add(1);  
	list.add(3);
	list.add(0);
	list.remove(0);


	char tick = 'a';    
	while (isRunning) {
		std::cout << "-------------------------" << std::endl;
		std::cout << "-      Linked List      -" << std::endl;
		std::cout << "-------------------------" << std::endl;
		std::cout << list.toString() << std::endl;
		std::cout << "press a) to add new item" << std::endl;
		std::cout << "press b) to delete an item" << std::endl;
		std::cout << "press c) to show list count" << std::endl;
		std::cout << "press d) to show all items" << std::endl;
		std::cout << "press e) to exit" << std::endl;

		char line[100];
		std::cin >> line;
		int rand_num = list.getSize() > 0 ? rand() % list.getSize() : 0;

		switch (line[0]) {
		case 'a':
			std::cout << "------------" << std::endl;
			std::cout << "Linked List:" << std::endl;
			std::cout << "Random Number: " << rand_num <<" has been added..." << std::endl;
			std::cout << "------------" << std::endl;
			list.add(rand_num);  
			break;
		case 'b':  
			std::cout << "------------" << std::endl;
			std::cout << "Linked List:" << std::endl;
			std::cout << "Removing random index: [" << list.getSize() - 1 - rand_num << "]..." << std::endl;
			std::cout << "------------" << std::endl;
			list.remove(rand_num);
			std::cout << std::endl;
			break;
		case 'd':
			std::cout << "------------" << std::endl;
			std::cout << "Linked List:" << std::endl;
			std::cout << list.toString() << std::endl;
			std::cout << "------------" << std::endl;
			break;    
		case 'c':
			std::cout << "------------" << std::endl;
			std::cout << "Item Count:" << std::endl;
			std::cout << list.getSize() << std::endl;
			std::cout << "------------" << std::endl;
			break;

		case 'e':
			isRunning = false;
			break;

		case 'r':
			std::cout << "------------" << std::endl;
			std::cout << "Clear() List:" << std::endl;
			list.clear();
			std::cout << list.toString() << std::endl;
			std::cout << "------------" << std::endl;
			break;
		default:
			std::cout << "Not an option" << std::endl;
			break;
		}


	}
}

int main() {
	menu();
}