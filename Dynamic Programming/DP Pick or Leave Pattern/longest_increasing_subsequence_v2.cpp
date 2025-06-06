// https://leetcode.com/problems/longest-increasing-subsequence/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 2500 + 1;
vector<int> arr;
int memory[MAX];

/*
 * Approach:
 * Dynamic Programming Memoization (pick next mask one approach)
 *
 * Complexity:
 * Time Complexity : O(N^2)
 * Space Complexity : O(N) where N is the max index
 */
int longest_increasing_subsequence(int idx)
{
    if (idx == (int)arr.size())
        return 0;

    auto &ret = memory[idx];
    if (ret != -1)
        return ret;

    ret = 0; // Maximize among all valid positions after i
    for (int j = idx + 1; j < (int)arr.size(); j++)
        if (arr[idx] < arr[j])
            ret = max(ret, longest_increasing_subsequence(j)); // take jth position after i

    ret++; // add ith position
    return ret;
}

int length_of_LIS(vector<int> &nums)
{
    memset(memory, -1, sizeof(memory));
    arr = nums;
    int result = 0;
    for (int j = 0; j < (int)arr.size(); ++j)
    {
        int start = longest_increasing_subsequence(j); // Start with i
        result = max(result, start);
    }
    return result;
}

int length_of_LIS_v2(vector<int> &nums)
{
    memset(memory, -1, sizeof(memory));
    arr = nums;
    arr.insert(arr.begin(), INT_MIN);
    return longest_increasing_subsequence(0) - 1; // -1 for the extra element
    // We can do simple workarounds to remove this loop
    // E.g. by inserting INT_MIN at numList[0] and only return LIS(0)
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // speed reading

    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << length_of_LIS(nums) << endl;
    // cout << length_of_LIS_v2(nums) << endl;
    return 0;
}