#include <bits/stdc++.h>
using namespace std;

vector<int> values;
const int MAX_IDX = 500 + 1, MAX_SUM = 2000 + 1;
int memory[MAX_IDX][MAX_SUM];

/*
 * Approach:
 * Dynamic Programming Memoization (pick or leave approach)
 *
 * Complexity:
 * Time Complexity : O(NM)
 * Space Complexity : O(NM) where N is the max index and M is the max sum
 */
bool subset_sum(int idx, int remaining_sum)
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
    if (subset_sum(idx + 1, remaining_sum))
        return ret = true;

    // pick this value
    return ret = subset_sum(idx + 1, remaining_sum - values[idx]);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // speed reading

    int target, n;
    cin >> target >> n;

    values.resize(n);

    for (int i = 0; i < n; i++)
        cin >> values[i];

    memset(memory, -1, sizeof(memory));
    cout << subset_sum(0, target) << endl;

    return 0;
}