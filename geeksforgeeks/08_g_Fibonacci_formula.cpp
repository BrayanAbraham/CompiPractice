//Not Reliable
#include <bits/stdc++.h>
#define loop(i, a, b) for (int i = a; i < b; i++)
using namespace std;

int fib(int n)
{
    double a = (1 + sqrt(5)) / 2;
    return round(pow(a, n)) / sqrt(5);
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n);
    return 0;
}