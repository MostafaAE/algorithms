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

    int change(int amount, vector<int> &numbers)
    {
        // Non-rechable cases should have answer 0
        memset(memory, 0, sizeof(memory));

        int sz = numbers.size();
        // Base case: Given any coin, we can make amount 0 with 1 way
        for (int idx = 0; idx < sz; ++idx)
            memory[idx][0] = 1;

        for (int idx = 0; idx < sz; ++idx)
        {
            for (int target = 0; target <= amount; ++target)
            {
                if (idx)
                    memory[idx][target] = memory[idx - 1][target];
                if (target - numbers[idx] >= 0)
                    memory[idx][target] += memory[idx][target - numbers[idx]];
            }
        }
        return memory[numbers.size() - 1][amount];
    }
};

int main()
{
    vector<int> numbers{5, 2, 1};
    int amount = 5;
    cout << Solution().change(amount, numbers);

    return 0;
}
