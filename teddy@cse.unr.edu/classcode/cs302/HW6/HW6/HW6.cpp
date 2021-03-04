#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>


int main() {

	using namespace std;
	srand(time(NULL));

	vector<int> nums;

	int tmp, count = 0;
	float mean = 0;

	for (; count < 100; count++) {
		tmp = rand() % 1000;
		mean += tmp;
		nums.push_back(tmp);
	}

	mean /= 100;

	make_heap(nums.begin(), nums.end());

	nums.push_back(mean);
	push_heap(nums.begin(), nums.end());

	cout << "\n-------------------------------\nMax number before being deleted:\n-------------------------------\n" << nums.front() << endl;
	pop_heap(nums.begin(), nums.end());

	nums.pop_back();
	cout << "\n-------------------------------\nMax Number after being deleted:\n-------------------------------\n" << nums.front() << endl;

	cout << endl << "\n-------------------------------\nThe heap before the sort:\n-------------------------------\n";

	for (auto value : nums) {
		cout << value << " ";
	}

	sort_heap(nums.begin(), nums.end());

	cout << endl << "\n-------------------------------\nThe heap after the sort:\n-------------------------------\n";
	for (int i : nums) {
		cout << i << " ";
	}

	cout << endl;

	return 0;
}

