#include <bits/stdc++.h>
using namespace std;

const int MAX = 100 + 1;

int memory[MAX][MAX];
vector<pair<int, int>> matrix_size;
/*
 * Approach:
 * Dynamic Programming Memoization
 *
 * Complexity:
 * Time Complexity : O(N^3)
 * Space Complexity : O(N^2)
 */

int mcm(int start_idx, int end_idx)
{
    // a single matrix: no multiplication
    if (start_idx == end_idx)
        return 0;

    auto &ret = memory[start_idx][end_idx];
    if (ret != -1)
        return ret;

    ret = INT_MAX;
    // try all the possible splits
    for (int k = start_idx; k < end_idx; k++)
    {
        int block_mult = matrix_size[start_idx].first * matrix_size[k].second * matrix_size[end_idx].second;

        int sub1 = mcm(start_idx, k);
        int sub2 = mcm(k + 1, end_idx);
        int total_operations = block_mult + sub1 + sub2;
        ret = min(ret, total_operations);
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // speed reading

    int n;
    cin >> n;
    matrix_size.resize(n);

    for (int i = 0; i < n; i++)
        cin >> matrix_size[i].first >> matrix_size[i].second;

    memset(memory, -1, sizeof(memory));

    cout << mcm(0, n - 1) << endl;

    return 0;
}

/*
Input:
3
5 10
10 19
19 7

Output:
1615
*/