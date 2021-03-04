#ifndef __SELECTION_SORT_CPP__
#define __SELECTION_SORT_CPP__

#include "SelectionSort.h"
#include "Metrics.h"
#include <cmath>
#include <algorithm>


int mindex(int start, std::vector<int>& list) {
	int m = 107;
	int mi = -1; // mindex
	Metrics::comparisions++;
	for (int i = start; i < list.size(); i++) {
		Metrics::comparisions+=2;
		if (m > list[i]) {
			m = list[i];
			mi = i;
		}
	}

	return mi;
}

void SelectionSort::selection(std::vector<int>& list)
{

	int n = 0;
	Metrics::comparisions++;
	while (n < list.size() - 1) {
		Metrics::comparisions++;
		int min = mindex(n, list);
		std::swap(list[n], list[min]);
		Metrics::swaps++;
		n++;
	}
}

#endif