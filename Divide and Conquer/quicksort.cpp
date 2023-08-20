#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <limits>
#include <random>
using namespace std;

// Function to partition the array and return the pivot index
int partition(vector<int> &lst, int start, int end)
{
	int pivot = lst[end];
	int i = start - 1;

	for (int j = start; j < end; j++)
	{
		if (lst[j] < pivot)
		{
			i++;
			swap(lst[i], lst[j]);
		}
	}

	swap(lst[i + 1], lst[end]);
	return i + 1;
}

// Function to partition the array and return the pivot index based on count approach
int partition2(vector<int> &lst, int start, int end)
{
	int pivot = lst[end];

	// Count how many numbers are less than the pivot
	int count{};
	for (int i = start; i < end; i++)
		if (lst[i] < pivot)
			count++;

	// Put the pivot in its right position
	int pivot_idx = start + count;
	swap(lst[end], lst[pivot_idx]);

	// Rearrange elements based on the pivot element
	for (int s = start, e = end; s < pivot_idx && e > pivot_idx; s++, e--)
	{
		while (lst[s] < pivot)
			s++;

		while (lst[e] > pivot)
			e--;

		if (s < pivot_idx && e > pivot_idx)
			swap(lst[s], lst[e]);
	}

	return pivot_idx;
}

// Quicksort function
void quicksort(vector<int> &lst, int start, int end)
{
	if (start >= end)
		return;

	int pivot = partition2(lst, start, end);
	quicksort(lst, start, pivot - 1);
	quicksort(lst, pivot + 1, end);
}

void quicksort(vector<int> &lst)
{
	int n = lst.size();

	quicksort(lst, 0, n - 1);
}

// Utility function to print the array
void printArray(const vector<int> &arr)
{
	for (int num : arr)
	{
		cout << num << " ";
	}
	cout << endl;
}

int main()
{

	vector<int> lst{12, 35, 87, 26, 9, 28, 7};

	quicksort(lst);

	printArray(lst);

	// 7 9 12 26 28 35 87

	return 0;
}
