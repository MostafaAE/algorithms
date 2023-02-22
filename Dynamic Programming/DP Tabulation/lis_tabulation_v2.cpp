// https://leetcode.com/problems/longest-increasing-subsequence/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 2500 + 1;
int memory[MAX];

/*
 * Approach:
 * Dynamic Programming Tabulation
 *
 * Complexity:
 * Time Complexity : O(N^2)
 * Space Complexity : O(N) where N is the max index
 */
int longest_increasing_subsequence(vector<int> &nums)
{
    nums.push_back(INT_MAX);

    // base case
    memory[0] = 1;

    for (int i = 1; i < (int)nums.size(); i++)
    {
        int &ret = memory[i];
        ret = 1;
        for (int j = i - 1; j >= 0; j--)
            if (nums[j] < nums[i])
                ret = max(ret, 1 + memory[j]);
    }

    return memory[nums.size() - 1] - 1;
}

int main()
{
    // ios_base::sync_with_stdio(false), cin.tie(nullptr); // speed reading

    int n;
    cin >> n;
    memset(memory, -1, sizeof(memory));

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << longest_increasing_subsequence(nums) << endl;
    return 0;
}

/*
Input:
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15

Output:
6
*/