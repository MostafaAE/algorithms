#include <bits/stdc++.h>
using namespace std;

/*
 * basic binary search algorithm
 *
 * Complexity:
 * Time Complexity : O(logn)
 * Space Complexity : O(1)
 */
int binary_search(vector<int> &nums, int target)
{
    int start{}, end{(int)nums.size() - 1};

    while (start <= end)
    {
        // prevent overflow
        int mid = start + (end - start) / 2;

        if (target == nums[mid])
            return mid;

        else if (target < nums[mid])
            end = mid - 1;

        else
            start = mid + 1;
    }

    return -1;
}

int main()
{
    vector<int> nums{0, 5, 13, 19, 22, 41, 55, 68, 72, 81, 98};

    cout << binary_search(nums, 0) << endl;   // 0
    cout << binary_search(nums, 98) << endl;  // 10
    cout << binary_search(nums, 68) << endl;  // 7
    cout << binary_search(nums, -5) << endl;  //-1
    cout << binary_search(nums, 105) << endl; //-1

    // must see it, otherwise RTE
    cout << "\n\nNO RTE\n";
    return 0;
}