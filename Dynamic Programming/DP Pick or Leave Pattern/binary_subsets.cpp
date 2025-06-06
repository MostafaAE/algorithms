#include <bits/stdc++.h>
using namespace std;

void print_number(int num, int len)
{
    if (!len)
        return;

    print_number(num >> 1, len - 1);
    cout << (num & 1);
}

void generate_subsets(int len)
{
    for (int i = 0; i < (1 << len); i++)
    {
        print_number(i, len);
        cout << endl;
    }
}

string res = "    ";
void generate_subsets_v2(int idx)
{
    if (idx == res.size())
    {
        cout << res << endl;
        return;
    }

    res[idx] = '0';
    generate_subsets_v2(idx + 1);

    res[idx] = '1';
    generate_subsets_v2(idx + 1);

    res[idx] = ' ';
}

int main()
{
    generate_subsets(4);
    // generate_subsets_v2(0);
    // must see it, otherwise RTE
    cout << "\n\nNO RTE\n";
    return 0;
}