#include <iostream>
#include <cstring> // memset
using namespace std;

typedef long long ll;
const int MAX = 80 + 1;
ll memory[MAX];

/*
 * Complexity:
 * Time Complexity : O(n)
 * Space Complexity : O(n)
 */
ll fib(int n)
{
    if (n <= 1)
        return 1;

    ll &ret = memory[n];

    if (ret != -1)
        return ret;
    return ret = fib(n - 1) + fib(n - 2);
}
int main()
{
    // set array with -1
    memset(memory, -1, sizeof(memory));

    cout << fib(80) << "\n"; // 37889062373143906

    return 0;
}