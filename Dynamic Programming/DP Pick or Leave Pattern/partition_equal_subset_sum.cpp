// https : // leetcode.com/problems/partition-equal-subset-sum/

#include <bits/stdc++.h>
using namespace std;

const int MAX_IDX = 200, MAX_SUM = 100 * 200 + 1;
int memory[MAX_IDX][MAX_SUM];

/*
 * Approach:
 * Dynamic Programming Memoization (pick or leave approach)
 *
 * Complexity:
 * Time Complexity : O(NM)
 * Space Complexity : O(NM) where N is the max index and M is the max sum
 */
bool subset_sum(vector<int> &values, int idx, int remaining_sum)
{
    if (remaining_sum < 0)
        return false;

    if (remaining_sum == 0)
        return true;

    // can't find a combination
    if (idx == values.size())
        return false;

    auto &ret = memory[idx][remaining_sum];
    if (ret != -1)
        return ret;

    // leave this value
    if (subset_sum(values, idx + 1, remaining_sum))
        return ret = true;

    // pick this value
    return ret = subset_sum(values, idx + 1, remaining_sum - values[idx]);
}

// Reduce the problem to the "subset sum" problem then solve it
bool can_partition(vector<int> &values)
{
    int totalSum = accumulate(values.begin(), values.end(), 0);
    memset(memory, -1, sizeof(memory));

    // if the sum is odd then we can't partition
    if (totalSum & 1)
        return false;

    // return if we can partition
    return subset_sum(values, 0, totalSum / 2);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // speed reading
    vector<int> values;

    int n;
    cin >> n;

    values.resize(n);

    for (int i = 0; i < n; i++)
        cin >> values[i];

    cout << can_partition(values) << endl;

    return 0;
}