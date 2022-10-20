#include <bits/stdc++.h>
using namespace std;

/*
 * Complexity:
 * Time Complexity : O(n^2)
 * Space Complexity : O(1)
 */
void selection_sort(vector<int> &nums)
{
    // select an index, then search for the minimum element in the rest of the array
    // and insert it in selected index
    int n = (int)nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        // find the minimum element in the unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (nums[j] < nums[min_idx])
                minIdx = j;

        // put the minimum element in its right position
        swap(nums[i], nums[min_idx]);
    }
}

void print_vec(const vector<int> &nums)
{
    for (int num : nums)
        cout << num << " ";
    cout << "\n";
}

int main()
{
    vector<int> nums{5, 4, 3, 6, 2, 1, 7, 10, 9, 8, 2, 3, 4};

    print_vec(nums); // 5 4 3 6 2 1 7 10 9 8 2 3 4

    selection_sort(nums);

    print_vec(nums); // 1 2 2 3 3 4 4 5 6 7 8 9 10

    // must see it, otherwise RTE
    cout << "\n\nNO RTE\n";
    return 0;
}