// https://leetcode.com/problems/longest-common-subsequence/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 1;
string str1, str2;
int memory[MAX][MAX];

/*
 * Approach:
 * Dynamic Programming Memoization (pick or leave approach)
 *
 * Complexity:
 * Time Complexity : O(NM)
 * Space Complexity : O(NM) where N is str1.length, and M is str2.length
 */
int longest_common_subsequence(int idx1, int idx2)
{
    if (idx1 == (int)str1.size() || idx2 == (int)str2.size())
        return 0;

    auto &ret = memory[idx1][idx2];
    if (ret != -1)
        return ret;

    // pick from both
    if (str1[idx1] == str2[idx2])
        return ret = 1 + longest_common_subsequence(idx1 + 1, idx2 + 1);

    // leave from str1
    int choice1 = longest_common_subsequence(idx1 + 1, idx2);
    // leave from str2
    int choice2 = longest_common_subsequence(idx1, idx2 + 1);

    return ret = max(choice1, choice2);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // speed reading

    cin >> str1 >> str2;

    memset(memory, -1, sizeof(memory));

    cout << longest_common_subsequence(0, 0) << endl;

    return 0;
}