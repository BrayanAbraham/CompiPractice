#include <bits/stdc++.h>
#define loop(i, a, b) for (int i = a; i < b; i++)
using namespace std;

int stirling(int n, int k)
{
    int dp[n + 1][k + 1] = {0};
    loop(i, 0, n + 1)
    {
        dp[i][0] = 0;
    }
    loop(i, 0, k + 1)
    {
        dp[0][i] = 0;
    }
    loop(i, 1, n + 1)
    {
        loop(j, 1, k + 1)
        {
            dp[i][j] = (i == j) ? 1 : j * dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }
    return dp[n][k];
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << stirling(n, k);
    return 0;
}