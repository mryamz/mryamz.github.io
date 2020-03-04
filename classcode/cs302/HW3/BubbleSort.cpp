#ifndef __BUBBLE_SORT_CPP__
#define __BUBBLE_SORT_CPP__

#include <algorithm> 
#include "BubbleSort.h"
#include "Metrics.h"


void BubbleSort::bubble(std::vector<int>& list)
{
	int n = list.size();

	for(int k = 0; k < n; k++) {
		Metrics::comparisions++;

		for (int i = n - 1; i > 1; i--) {
			Metrics::comparisions++;

			int a = list[i - 1];
			int b = list[i];
			if (a > b) {
				Metrics::comparisions++;

				std::swap(list[i - 1], list[i]);
				Metrics::swaps++;
			}
		}
	}
}

#endif