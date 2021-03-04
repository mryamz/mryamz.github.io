
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono> 

#include "BubbleSort.h"
#include "QuickSort.h"
#include "SelectionSort.h"
#include "Metrics.h"

namespace Metrics {

	long swaps;
	long comparisions;

};

void print_vector(std::vector<int>& list) {
	for (int i = 0; i < list.size(); i++) {
		std::cout << list[i] << "\n";
	}
}

void setlist(std::vector<int>& list, std::string path) {
	std::fstream f(path);

	int x;
	while (f >> x) {
		list.push_back(x);
	}
}

int main() {
	std::vector<int> list;


	BubbleSort bubble;
	QuickSort quick;
	SelectionSort selection;

	system("touch algorithm_metrics.csv");

	std::ofstream csv("algorithm_metrics.csv");
	csv << "ALGORITHM,CPU TIME (MILLIS),SWAPS,COMPARISIONS\n";

	using namespace std::chrono;

	// MAKE .CSV FILE

	// BUBBLE WORST CASE 1,000
	for (int i = 0; i < 10; i++) {
		std::cout << i << std::endl;
		setlist(list, "1000.txt");
		auto start = high_resolution_clock::now();
		bubble.bubble(list);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		csv << "bubble sort 1,000," << duration.count() << "," << Metrics::swaps << "," << Metrics::comparisions << "\n";

		list.clear();
		Metrics::comparisions = Metrics::swaps = 0;
	}

	csv << "\n";

	// BUBBLE WORST CASE 10,000
	for (int i = 0; i < 10; i++) {
		std::cout << i << std::endl;
		setlist(list, "10000.txt");
		auto start = high_resolution_clock::now();
		bubble.bubble(list);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		csv << "bubble sort 10,000," << duration.count() << "," << Metrics::swaps << "," << Metrics::comparisions << "\n";

		list.clear();
		Metrics::comparisions = Metrics::swaps = 0;
	}
	csv << "\n";

	// BUBBLE WORST CASE 100,000
	for (int i = 0; i < 10; i++) {
		std::cout << i << std::endl;
		setlist(list, "100000.txt");
		auto start = high_resolution_clock::now();
		bubble.bubble(list);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		csv << "bubble sort 100,000," << duration.count() << "," << Metrics::swaps << "," << Metrics::comparisions << "\n";

		list.clear();
		Metrics::comparisions = Metrics::swaps = 0;
	}
	csv << "\n";

}