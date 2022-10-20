#include <bits/stdc++.h>
using namespace std;

/*
 * Complexity:
 * Time Complexity : O(n^2)
 * Space Complexity : O(1)
 */
void insertion_sort(vector<int> &nums)
{
    // For each number:add it in the previous sorted sub-array
    for (int i = 1; i < (int)nums.size(); i++)
    {
        int key = nums[i];
        int j = i - 1;
        // shift and add in the right location
        while (j >= 0 && nums[j] > key)
        {
            nums[j + 1] = nums[j]; // shift right
            j--;
        }
        // insert the element in its right location
        nums[j + 1] = key;
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

    insertion_sort(nums);

    print_vec(nums); // 1 2 2 3 3 4 4 5 6 7 8 9 10

    // must see it, otherwise RTE
    cout << "\n\nNO RTE\n";
    return 0;
}