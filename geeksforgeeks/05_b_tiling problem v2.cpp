/*Given a “2 x n” board and tiles of size “2 x 1”, count the number
 of ways to tile the given board using the 2 x 1 tiles. A tile can 
 either be placed horizontally i.e., as a 1 x 2 tile or vertically 
 i.e., as 2 x 1 tile. 
*/

#include <bits/stdc++.h>
#define loop(i, a, b) for (int i = a; i < b; i++)
using namespace std;

int fib(int n)
{
    int a = 1, b = 2, c;
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    loop(i, 3, n + 1)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n);
    return 0;
}