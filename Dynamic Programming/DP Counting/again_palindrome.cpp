// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1558

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 60 + 1;
int memory[MAX][MAX];
string str;

/*
 * Approach:
 * Dynamic Programming Memoization
 * Counting DP
 *
 * Complexity:
 * Time Complexity : O(N^2)
 * Space Complexity : O(N^2) where N is the max index
 */

// Find the number of ways we can remove 0 or more characters such that the remaining is palindrome
ll numOfWays(int left, int right)
{
  if (left == right) // single letter
    return 1;        // A: 1

  if (left + 1 == right)                  // 2 letters
    return 2 + (str[left] == str[right]); // AB: 2 - AA: 3

  auto &ret = memory[left][right];
  if (ret != -1)
    return ret;

  ret = 0;

  if (str[left] == str[right])
    // +1 for the whole string with removed body
    ret += 1 + numOfWays(left + 1, right - 1);

  ret += numOfWays(left + 1, right);
  ret += numOfWays(left, right - 1);
  // remove duplication of (left+1, right), (left, right-1)
  ret -= numOfWays(left + 1, right - 1);

  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false), cin.tie(nullptr); // speed reading

  int t;
  cin >> t;
  while (t--)
  {
    cin >> str;
    memset(memory, -1, sizeof(memory));
    cout << numOfWays(0, (int)str.size() - 1) << endl;
  }

  return 0;
}

/*
Input:
3
BAOBAB
AAAA
ABA

Output:
22
15
5
*/