#include <bits/stdc++.h>
using namespace std;

double power(double x, int y)
{
    if (y == 0)
    {
        return 1;
    }
    double temp = power(x, y / 2);
    if (y % 2 == 0)
    {
        return temp * temp;
    }
    else
    {
        if (y > 0)
        {
            return x * temp * temp;
        }
        else
        {
            return temp * temp / x;
        }
    }
}

int main()
{
    cout << power(2, 4) << " " << power(2, -4) << " " << power(2, 3) << " " << power(2, -3) << " ";
    return 0;
}