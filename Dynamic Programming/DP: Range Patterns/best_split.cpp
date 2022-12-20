// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=676

#include <bits/stdc++.h>
using namespace std;

const int MAX = 100 + 1;

int memory[MAX];
vector<int> quantity, price;
/*
 * Approach:
 * Dynamic Programming Memoization
 *
 * Complexity:
 * Time Complexity : O(N^2)
 * Space Complexity : O(N) where N is the max index
 */

// Find the best split of the array starting from this index
int best_split(int idx)
{
    if (idx >= (int)quantity.size())
        return 0;

    auto &ret = memory[idx];
    if (ret != -1)
        return ret;

    // For this start_idx, brute-force all possible endings for the FIRST sub-array
    ret = INT_MAX;
    int sum = 0;
    for (int block_end = idx; block_end < (int)quantity.size(); block_end++)
    {
        sum += quantity[block_end];

        int block_cost = (sum + 10) * price[block_end];
        int total_choice_cost = block_cost + best_split(block_end + 1);
        ret = min(ret, total_choice_cost);
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // speed reading

    int n;
    cin >> n;
    quantity.resize(n);
    price.resize(n);

    for (int i = 0; i < n; i++)
        cin >> quantity[i] >> price[i];

    memset(memory, -1, sizeof(memory));

    cout << best_split(0) << endl;

    return 0;
}

/*
Input:
3
1 10
1 11
100 12

Output:
1344
*/