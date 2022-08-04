#include <bits/stdc++.h>
#define loop(i, a, b) for (int i = a; i < b; i++)
using namespace std;

int polynomial(int n, int k)
{
    int dp[n + 1][k + 1];
    loop(i, 0, n + 1)
    {
        loop(j, 0, min(i + 1, k + 1))
        {
            if (j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j] + (j * dp[i - 1][j - 1]);
            dp[i][j + 1] = 0;
        }
    }
    return dp[n][k];
}

int main()
{
    cout << polynomial(10, 2);
    return 0;
}