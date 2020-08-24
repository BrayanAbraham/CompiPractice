/*
Bell(n) = sum from k=0 to n S(n,k)
s(n+1,k) = k*S(n,k)+S(n,k-1)
1
1 2
2 3 5
5 7 10 15
15 20 27 37 52 
*/
#include <bits/stdc++.h>
#define loop(i, a, b) for (int i = a; i < b; i++)
using namespace std;

int bell(int n)
{
    int dp[n + 1][n + 1];
    dp[0][0] = 1;
    loop(i, 1, n + 1)
    {
        loop(j, 0, i + 1)
        {
            dp[i][j] = (j == 0) ? dp[i - 1][i - 1] : dp[i][j - 1] + dp[i - 1][j - 1];
        }
    }
    return dp[n][0];
}

int main()
{
    int n;
    cin >> n;
    cout << bell(n);
    return 0;
}