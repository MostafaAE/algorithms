// https://leetcode.com/problems/integer-break/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 58 + 1;
int memory[MAX];

/*
 * Approach:
 * Dynamic Programming Memoization
 *
 * Complexity:
 * Time Complexity : O(N^2)
 * Space Complexity : O(N)
 */

int maxProduct(int n)
{
    if (n == 1)
        return n;

    int &ret = memory[n];
    if (ret != -1)
        return ret;

    // default: don't divide
    ret = n;

    for (int i = 1; i < n; i++)
        ret = max(ret, i * maxProduct(n - i));

    return ret;
}

int integerBreak(int n)
{
    if (n == 2 || n == 3)
        return n - 1;

    memset(memory, -1, sizeof(memory));
    return maxProduct(n);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // speed reading
    int n;
    cin >> n;
    cout << integerBreak(n) << endl;

    return 0;
}