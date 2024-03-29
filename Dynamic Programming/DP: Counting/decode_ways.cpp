// https://leetcode.com/problems/decode-ways/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 100 + 1;
int memory[MAX];
string str;

/*
 * Approach:
 * Dynamic Programming Memoization
 *
 * Counting DP
 *
 * Complexity:
 * Time Complexity : O(N)
 * Space Complexity : O(N)
 */
int decode(int idx)
{
  // one valid way
  if (idx >= (int)str.size())
    return 1;

  // invalid (no ways)
  if (str[idx] == '0')
    return 0;

  int &ret = memory[idx];
  if (ret != -1)
    return ret;

  // 2 cases: 1 digit or 2 digits
  ret = decode(idx + 1);
  if (idx < (int)str.size() - 1 && (str[idx] == '1' || str[idx] == '2' && str[idx + 1] <= '6'))
    ret += decode(idx + 2);

  return ret;
}

int numDecodings(string s)
{
  str = s;
  memset(memory, -1, sizeof(memory));
  return decode(0);
}

int main()
{
  cin >> str;

  cout << numDecodings(str) << endl;

  return 0;
}
