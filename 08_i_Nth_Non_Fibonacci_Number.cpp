#include <bits/stdc++.h>
using namespace std;

int nonFib(int n)
{
    int c = 3, p = 2, pp = 1;
    while (n > 0)
    {
        pp = p;
        p = c;
        c = pp + p;
        n = n - c + p + 1;
    }
    n = n + c - p - 1;
    return p + n;
}

int main()
{
    int n = 10;
    cout << nonFib(n);
    return 0;
}