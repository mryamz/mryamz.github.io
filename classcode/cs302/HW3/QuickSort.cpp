#ifndef __QUICK_SORT_CPP__
#define __QUICK_SORT_CPP__


#include "QuickSort.h"
#include <algorithm>
#include <iostream>
#include <cmath>
#include <random>
#include "Metrics.h"


void QuickSort::quick(std::vector<int>& list, int left, int right)
{
	int pivot = right - 1;

	int l = left;
	int r = right;

	Metrics::comparisions++;
	while (l < r) {
		Metrics::comparisions += 4;


		while (list[l] < list[pivot]) 
			l++;
		
		while (list[r] > list[pivot]) 
			r--;


		if (l <= r) {
			std::swap(list[l], list[r]);
			l++;
			r--;
			Metrics::swaps++;

		}
	}

	Metrics::comparisions += 2;
	if (left < r)
		quick(list, left, r);
	
	if (l < right)
		quick(list, l, right);
	
}

#endif