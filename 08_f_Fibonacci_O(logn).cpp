#include <bits/stdc++.h>
#define loop(i, a, b) for (int i = a; i < b; i++)
#define MAX 1000
using namespace std;

int f[MAX] = {0};

int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1 || n == 2)
    {
        return f[n] = 1;
    }
    if (f[n])
    {
        return f[n];
    }

    int k = (n & 1) ? (n + 1) / 2 : n / 2;

    f[n] = (n & 1) ? (fib(k) * fib(k)) + (fib(k - 1) * fib(k - 1)) : (2 * fib(k - 1) + fib(k)) * fib(k);
    return f[n];
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n);
    return 0;
}