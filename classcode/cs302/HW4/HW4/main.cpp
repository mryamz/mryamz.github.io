

#include <iostream>
#include "PriorityQueue.h"
#include "Queue.h"



int main() {
	using namespace std;

	PriorityQueue<char> q;
	 
	q.insert('e', 97);
	q.insert('b', 99);
	q.insert('a', 100);
	q.insert('c', 98 );

	q.debugIO();
	q.remove();
	q.debugIO();


}