#include <iostream>
using namespace std;

typedef long long ll;

/*
 * Complexity:
 * Time Complexity : O(n)
 * Space Complexity : O(n)
 */
int main()
{
    const int MAX{80 + 1};
    ll fib[MAX]{1, 1}; // base cases

    for (int i = 2; i < MAX; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];

    cout << fib[80] << "\n"; // 37889062373143906

    return 0;
}