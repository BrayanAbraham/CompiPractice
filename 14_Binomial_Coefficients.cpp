#include <bits/stdc++.h>
#define loop(i, a, b) for (int i = a; i < b; i++)
using namespace std;

int binomial(int n, int k)
{
    int dp[k + 1];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    loop(i, 0, n + 1)
    {
        for (int j = min(i, k); j > 0; j--)
        {
            dp[j] = dp[j] + dp[j - 1];
        }
    }
    return dp[k];
}

int main()
{
    cout << binomial(10, 5);
    return 0;
}