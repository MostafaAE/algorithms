// https://leetcode.com/problems/coin-change-2/

#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <cassert>
using namespace std;

const int MAX_N = 300 + 1;
const int MAX_T = 5000 + 1;
int memory[2][MAX_T];

class Solution
{
public:
    int change(int amount, vector<int> &numbers)
    {
        // Non-rechable cases should have answer 0
        memset(memory, 0, sizeof(memory));

        for (int idx = 0; idx < 2; ++idx)
            memory[idx][0] = 1;

        int sz = numbers.size();
        int cur = 1; // binary
        for (int idx = 0; idx < sz; ++idx)
        {
            for (int target = 0; target <= amount; ++target)
            {
                if (idx)
                    memory[cur][target] = memory[1 - cur][target];
                if (target - numbers[idx] >= 0)
                    memory[cur][target] += memory[cur][target - numbers[idx]];
            }
            cur = 1 - cur;
        }
        return memory[1 - cur][amount];
    }
};

int main()
{
    vector<int> numbers{5, 2, 1};
    int amount = 5;
    cout << Solution().change(amount, numbers);

    return 0;
}
