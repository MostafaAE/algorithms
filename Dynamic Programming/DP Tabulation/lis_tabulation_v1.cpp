// https://leetcode.com/problems/longest-increasing-subsequence/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 2500 + 1;
int memory[MAX][MAX];

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
    int n = (int)nums.size();
    for (int i = (int)nums.size() - 1; i >= 0; i--)
    {
        for (int prev = 0; prev <= i; prev++)
        {
            if (prev == i)
                prev = n;

            if (i == n - 1)
            {
                if (prev == n || nums[prev] < nums[i])
                    memory[i][prev] = 1;
                else
                    memory[i][prev] = 0;
            }
            else
            {
                assert(memory[i + 1][prev] != -1); // verify for safety
                int leave = memory[i + 1][prev];   // leave

                // take
                int pick{};
                if (prev == n || nums[prev] < nums[i])
                {
                    assert(memory[i + 1][i] != -1);
                    pick = 1 + memory[i + 1][i];
                }
                memory[i][prev] = max(pick, leave);
            }
        }
    }

    return memory[0][n];
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