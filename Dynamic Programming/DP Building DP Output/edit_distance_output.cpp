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

void edit_distance_output(int idx1, int idx2)
{
    // if one of the strings is empty, then delete or insert the remaining of the other
    if (idx1 == (int)word1.size() && idx2 == (int)word2.size())
        return;

    if (idx1 == (int)word1.size())
    {
        cout << "In " + word1 + " insert at the end " + word2.substr(idx2) << endl;
        return;
    }

    if (idx2 == (int)word2.size())
    {
        cout << "In " + word1 + " delete at the end " + word1.substr(idx1) << endl;
        return;
    }
    int optimal = edit_distance(idx1, idx2);

    // no operation (same letter)
    if (word1[idx1] == word2[idx2])
    {
        edit_distance_output(idx1 + 1, idx2 + 1);
        return;
    }

    // deletion
    int deleteOp = 1 + edit_distance(idx1 + 1, idx2);

    // insertion
    int insertOp = 1 + edit_distance(idx1, idx2 + 1);

    // change
    int changeOp = 1 + edit_distance(idx1 + 1, idx2 + 1);

    if (optimal == deleteOp)
    {
        cout << "In " + word1 + " delete original idx " + to_string(idx1) + " letter " + word1[idx1] << endl;
        edit_distance_output(idx1 + 1, idx2);
    }
    else if (optimal == insertOp)
    {
        cout << "In " + word1 + " insert at original idx " + to_string(idx1) + " letter " + word2[idx2] << endl;
        edit_distance_output(idx1, idx2 + 1);
    }
    else
    {
        cout << "In " + word1 + " change letter at original idx " + to_string(idx1) + " letter " + word1[idx1] + " to letter " + word2[idx2] << endl;
        edit_distance_output(idx1 + 1, idx2 + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // speed reading

    cin >> word1 >> word2;

    memset(memory, -1, sizeof(memory));

    cout << "Steps for: " << word1 << " to " << word2 << endl;
    edit_distance_output(0, 0);
    cout << edit_distance(0, 0) << " steps in total" << endl;

    return 0;
}
/*
Input:
spakehz park

Output:
Steps for: spakehz to park
In spakehz delete original idx 0 letter s
In spakehz delete original idx 3 letter k
In spakehz delete original idx 4 letter e
In spakehz change letter at original idx 5 letter h to letter r
In spakehz change letter at original idx 6 letter z to letter k
5 steps in total
*/