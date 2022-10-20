#include <bits/stdc++.h>
using namespace std;

/*
 * Complexity:
 * Time Complexity : O(n^2)
 * Space Complexity : O(1)
 */
void insertion_sort(vector<int> &nums)
{
    // For each number:a dd it in the previous sorted sub-array
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

/*
 * This version sorts the elements in descending order
 * and utilizes the swap functionto reduce the code length, but in return it
 * performs more operations than the first version if the swap operation takes ~3 steps
 *
 * Complexity:
 * Time Complexity : O(n^2)
 * Space Complexity : O(1)
 */
void insertion_sort_v2(vector<int> &nums)
{
    // For each element: keep swapping it with the previous until it reaches
    // its right position in the previous sorted sub-array
    for (int i = 1; i < (int)nums.size(); i++)
        for (int j = i - 1; j >= 0 && nums[j] < nums[j + 1]; j--)
            swap(nums[j], nums[j + 1]);
}

void print_vec(const vector<int> &nums)
{
    for (int num : nums)
        cout << num << " ";
    cout << "\n";
}

void test_insertion_sort()
{
    vector<int> nums{5, 4, 3, 6, 2, 1, 7, 10, 9, 8, 2, 3, 4};
    print_vec(nums); // 5 4 3 6 2 1 7 10 9 8 2 3 4

    insertion_sort(nums);

    print_vec(nums); // 1 2 2 3 3 4 4 5 6 7 8 9 10
}

void test_insertion_sort_v2()
{
    vector<int> nums{5, 4, 3, 6, 2, 1, 7, 10, 9, 8, 2, 3, 4};
    print_vec(nums); // 5 4 3 6 2 1 7 10 9 8 2 3 4

    insertion_sort_v2(nums);

    print_vec(nums); // 10 9 8 7 6 5 4 4 3 3 2 2 1
}
int main()
{
    test_insertion_sort();
    test_insertion_sort_v2();

    // must see it, otherwise RTE
    cout << "\n\nNO RTE\n";
    return 0;
}