// https://leetcode.com/problems/coin-change-2/

#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <cassert>
using namespace std;

const int MAX_N = 300 + 1;
const int MAX_T = 5000 + 1;
int memory[MAX_N][MAX_T];

vector<int> numbers;

// backward: call count_conins_change(sz-1, amount)
int count_conins_change(int idx, int target)
{
    if (target < 0)
        return 0;
    if (target == 0)
        return 1; // one valid path
    if (idx == -1)
        return 0; // can't find combination

    auto &ret = memory[idx][target];
    if (ret != -1)
        return ret;

    int leave = count_conins_change(idx - 1, target);
    int take = count_conins_change(idx, target - numbers[idx]);
    return ret = leave + take;
}

class Solution
{
public:
    int change_rec(int amount, vector<int> &coins)
    {
        numbers = coins;
        memset(memory, -1, sizeof(memory));
        return count_conins_change(coins.size() - 1, amount);
    }

    // you can use a function to enjoy memoization flexibility

    int answer(int idx, int target)
    {
        if (target < 0)
            return 0;

        if (target == 0)
            return 1; // one valid path

        if (idx == -1)
            return 0; // can't find combination

        assert(memory[idx][target] != -1);
        return memory[idx][target];
    }

    int change(int amount, vector<int> &numbers)
    {
        memset(memory, -1, sizeof(memory));

        int sz = numbers.size();
        for (int idx = 0; idx < sz; ++idx)
        {
            // try amounts small to large to make sure smaller state exist
            for (int target = 0; target <= amount; ++target)
            {
                int leave = answer(idx - 1, target);
                int take = answer(idx, target - numbers[idx]);
                memory[idx][target] = leave + take;
            }
        }
        return memory[numbers.size() - 1][amount];
    }
};

int main()
{
    vector<int> numbers{1, 2, 5};
    int amount = 5;
    cout << Solution().change(amount, numbers);

    return 0;
}
