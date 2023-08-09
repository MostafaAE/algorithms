#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <limits>
#include <random>
using namespace std;

vector<int> tmp; // Create with lst size

void merge_sorted_subarrays(vector<int> &lst, int start, int md, int end)
{
	for (int i = start, j = md + 1, k = start; k <= end; k++)
	{
		if (i > md) // start is done
			tmp[k] = lst[j++];
		else if (j > end) // end is done
			tmp[k] = lst[i++];
		else if (lst[i] < lst[j]) // start is smaller
			tmp[k] = lst[i++];
		else
			tmp[k] = lst[j++];
	}
	for (int i = start; i <= end; i++)
		lst[i] = tmp[i];
}

void merge_sort(vector<int> &lst, int start, int end)
{
	if (start == end)
		return;

	int md = start + (end - start) / 2;
	merge_sort(lst, start, md);
	merge_sort(lst, md + 1, end);

	merge_sorted_subarrays(lst, start, md, end);
}

void merge_sort(vector<int> &lst)
{
	tmp = lst;
	merge_sort(lst, 0, (int)lst.size() - 1);
}

int main()
{

	vector<int> lst{12, 35, 87, 26, 9, 28, 7};

	merge_sort(lst);

	for (int i = 0; i < (int)lst.size(); ++i)
		cout << lst[i] << " ";
	cout << "\n";

	// 7 9 12 26 28 35 87

	return 0;
}
