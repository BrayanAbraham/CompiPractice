#include <bits/stdc++.h>
using namespace std;

int stirling(int n, int k)
{
    if (n == 0 || k == 0 || k > n)
    {
        return 0;
    }
    else if (n == k)
    {
        return 1;
    }
    else
    {
        return k * stirling(n - 1, k) + stirling(n - 1, k - 1);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << stirling(n, k);
    return 0;
}