#include <bits/stdc++.h>
using namespace std;

/*
 * Complexity:
 * Time Complexity : O(n+m)
 * Space Complexity : O(m)
 * where m is the max value in the array
 */
void count_sort(vector<int> &nums)
{
    int max_val = nums[0];
    int size = (int)nums.size();
    int idx{};

    // Find the largest element of the array
    // O(n)
    for (int i = 1; i < size; i++)
        if (nums[i] > max_val)
            max_val = nums[i];

    // Compute Frequency of each element in the array
    // O(n)
    vector<int> count(max_val + 1);
    for (int i = 0; i < size; i++)
        count[nums[i]]++;

    // Put the values back to the array
    // O(m+n)
    for (int i = 0; i <= max_val; i++)
    {
        for (int j = 0; j < count[i]; j++, idx++)
            nums[idx] = i;
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

    count_sort(nums);

    print_vec(nums); // 1 2 2 3 3 4 4 5 6 7 8 9 10

    // must see it, otherwise RTE
    cout << "\n\nNO RTE\n";
    return 0;
}