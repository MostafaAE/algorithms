// https://leetcode.com/problems/edit-distance/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 1;
string word1, word2;
int memory[MAX][MAX];

/*
 * Approach:
 * Dynamic Programming Memoization
 *
 * Complexity:
 * Time Complexity : O(NM)
 * Space Complexity : O(NM) where N is word1.length, and M is word2.length
 */
int edit_distance(int idx1, int idx2)
{
    // if one of the strings is empty, then delete or insert the remaining of the other
    if (idx1 == (int)word1.size() || idx2 == (int)word2.size())
        return ((int)word1.size() - idx1 + (int)word2.size() - idx2);

    int &ret = memory[idx1][idx2];
    if (ret != -1)
        return ret;

    // no operation (same letter)
    if (word1[idx1] == word2[idx2])
        return edit_distance(idx1 + 1, idx2 + 1);

    // deletion
    int deleteOp = 1 + edit_distance(idx1 + 1, idx2);

    // insertion
    int insertOp = 1 + edit_distance(idx1, idx2 + 1);

    // change
    int changeOp = 1 + edit_distance(idx1 + 1, idx2 + 1);

    return ret = min(deleteOp, min(insertOp, changeOp));
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // speed reading

    cin >> word1 >> word2;

    memset(memory, -1, sizeof(memory));

    cout << edit_distance(0, 0) << endl;

    return 0;
}