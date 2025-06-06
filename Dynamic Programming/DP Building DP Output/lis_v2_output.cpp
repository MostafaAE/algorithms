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

void lis_output(int idx)
{
    if (idx == (int)arr.size())
        return;

    if (idx)
        cout << "Pick: " << arr[idx] << endl;
    // Compute optimal and see which path generated it
    int optimal = longest_increasing_subsequence(idx);

    for (int j = idx + 1; j < (int)arr.size(); j++)
    {
        if (arr[idx] < arr[j])
        {
            if (optimal == 1 + longest_increasing_subsequence(j))
            {
                lis_output(j);
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // speed reading

    int n;
    cin >> n;
    arr.resize(n + 1);
    arr[0] = INT_MIN;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    memset(memory, -1, sizeof(memory));

    lis_output(0);

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