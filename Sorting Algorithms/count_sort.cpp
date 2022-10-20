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

/*
 * This count sort implementation will make the algorithm stable but will cause the following:
 *
 *  1) More memory writes
 *      count[i] += count[i - 1];  and count[array[i]] -= 1;
 *
 *  2) Bad Locality of reference
 *
 *  3) More memory vector<int> output(size);
 *      However, this is used to create a stable order algorithm!
 *      But a must to process backward
 *          for (int i = size - 1; i >= 0; --i)
 *
 * Complexity:
 * Time Complexity : O(n+m)
 * Space Complexity : O(n+m)
 * where m is the max value in the array
 */
vector<int> count_sort_v2(const vector<int> &array)
{
    int size = array.size();
    int mxVal = array[0];

    // Find the largest element of the array
    // O(n)
    for (int i = 1; i < size; ++i)
        if (array[i] > mxVal)
            mxVal = array[i];

    // Compute Frequency of each element in the array
    // O(n)
    vector<int> count(mxVal + 1); // zeros
    for (int i = 0; i < size; ++i)
        count[array[i]] += 1;

    // Accumulate the counting
    // O(m)
    for (int i = 1; i <= mxVal; ++i)
        count[i] += count[i - 1];

    // Find the index and put the number
    // O(n)
    vector<int> output(size);
    for (int i = size - 1; i >= 0; --i)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]] -= 1;
    }
    return output;
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