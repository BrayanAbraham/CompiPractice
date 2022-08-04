/*
There are 100 different types of caps each having a unique id from 1 to 100. 
Also, there are ‘n’ persons each having a collection of a variable number of 
caps. One day all of these persons decide to go in a party wearing a cap but 
to look unique they decided that none of them will wear the same type of cap. 
So, count the total number of arrangements or ways such that none of them is 
wearing the same type of cap
*/

#include <bits/stdc++.h>
#define loop(i, a, b) for (int i = a; i < b; i++)
#define lli long long int
#define MOD 1000000007
using namespace std;

vector<int> caplist[101];
int dp[1025][101];
int allmask;

lli countWaysUntil(int mask, int i)
{
    if (mask == allmask)
        return 1;

    if (i > 100)
        return 0;

    if (dp[mask][i] != -1)
        return dp[mask][i];

    lli ways = countWaysUntil(mask, i + 1);
    int size = caplist[i].size();
    loop(j, 0, size)
    {
        if (mask & (1 << caplist[i][j]))
            continue;
        else
            ways += countWaysUntil(mask | (1 << caplist[i][j]), i + 1);
        ways %= MOD;
    }
    return dp[mask][i] = ways;
}

void countWays(int n)
{
    string temp, str;
    int x;
    getline(cin, str);
    loop(i, 0, n)
    {
        getline(cin, str);
        stringstream ss(str);
        while (ss >> temp)
        {
            stringstream s;
            s << temp;
            s >> x;
            caplist[x].push_back(i);
        }
    }
    allmask = (1 << n) - 1;
    memset(dp, -1, sizeof dp);
    cout << countWaysUntil(0, 1) << endl;
}

int main()
{
    int n;
    cin >> n;
    countWays(n);
    return 0;
}