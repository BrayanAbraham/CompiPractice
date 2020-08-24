#include <bits/stdc++.h>
using namespace std;

int evenFibSum(int limit)
{
    if (limit < 2)
        return 0;

    int a = 0, b = 2;
    int sum = a + b;

    while (b < limit)
    {
        int c = 4 * b + a;
        if (c > limit)
        {
            break;
        }
        sum += c;
        a = b;
        b = c;
    }

    return sum;
}

int main()
{
    int limit = 400;
    cout << evenFibSum(limit);
    return 0;
}