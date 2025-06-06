#include <bits/stdc++.h>
using namespace std;

vector<int> weight, value;
const int MAX = 2000 + 1;
int memory[MAX][MAX];

/*
 * Approach:
 * Dynamic Programming Memoization
 *
 * Complexity:
 * Time Complexity : O(NW)
 * Space Complexity : O(NW) where N is the max index and W is the max weight
 */
int knapsack(int idx, int remaining_weight)
{
    if (idx == weight.size())
        return 0;

    auto &ret = memory[idx][remaining_weight];
    if (ret != -1)
        return ret;

    // leave this weight
    int leave = knapsack(idx + 1, remaining_weight);

    int pick{0};
    // pick this weight if we can
    if (weight[idx] <= remaining_weight)
        pick = value[idx] + knapsack(idx + 1, remaining_weight - weight[idx]);

    return ret = max(pick, leave);
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // speed reading

    int max_weight, n;
    cin >> max_weight >> n;

    weight.resize(n);
    value.resize(n);

    for (int i = 0; i < n; i++)
        cin >> weight[i] >> value[i];

    memset(memory, -1, sizeof(memory));
    cout << knapsack(0, max_weight) << endl;

    return 0;
}

// https://www.spoj.com/problems/KNAPSACK/