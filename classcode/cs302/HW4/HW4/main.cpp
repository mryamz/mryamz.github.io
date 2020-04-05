#include <iostream>
#include "PriorityQueue.h"
#include "Queue.h"



int main() {
	using namespace std;

	Queue<int> q;

	q.enque(5);
	q.enque(55);
	q.enque(58);
	q.enque(54);
	q.deque();
	q.deque();

	cout << "Queue Front : " << (q.front)->t << endl;

	cout << "Queue Rear : " << (q.back)->t;




}