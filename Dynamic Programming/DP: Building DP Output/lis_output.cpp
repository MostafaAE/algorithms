#include <bits/stdc++.h>
using namespace std;

const int MAX = 2500 + 1;
vector<int> arr;
int memory[MAX][MAX];

/*
 * Approach:
 * Dynamic Programming Memoization (pick or leave approach)
 *
 * Complexity:
 * Time Complexity : O(N^2)
 * Space Complexity : O(N^2) where N is the max index
 */
int longest_increasing_subsequence(int idx, int prev_idx)
{
    if (idx == arr.size())
        return 0;

    auto &ret = memory[idx][prev_idx];
    if (ret != -1)
        return ret;

    // leave this element
    int leave = longest_increasing_subsequence(idx + 1, prev_idx);

    int pick{};
    // pick this element if there is no previous or it is greater than the previous index
    if (prev_idx == arr.size() || arr[idx] > arr[prev_idx])
        pick = 1 + longest_increasing_subsequence(idx + 1, idx);

    return ret = max(pick, leave);
}

void lis_output(int idx, int prev_idx)
{
    if (idx == arr.size())
        return;

    // Compute optimal and see which path generated it
    int optimal = longest_increasing_subsequence(idx, prev_idx);

    // leave this element
    int leave = longest_increasing_subsequence(idx + 1, prev_idx);

    int pick{};
    // pick this element if there is no previous or it is greater than the previous index
    if (prev_idx == arr.size() || arr[idx] > arr[prev_idx])
        pick = 1 + longest_increasing_subsequence(idx + 1, idx);

    // print the optimal choice
    if (optimal == pick)
    {
        cout << "Pick: " << arr[idx] << endl;
        lis_output(idx + 1, idx);
    }
    else
        lis_output(idx + 1, prev_idx);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // speed reading

    int n;
    cin >> n;

    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    memset(memory, -1, sizeof(memory));

    // cout << longest_increasing_subsequence(0, n) << endl;
    lis_output(0, n);

    return 0;
}

/*
Input:
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15

Output:
Pick: 0
Pick: 4
Pick: 6
Pick: 9
Pick: 13
Pick: 15
*/