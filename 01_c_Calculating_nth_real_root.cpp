//Given two number x and n, find n-th root of x.
#include <bits/stdc++.h>
using namespace std;

int search(double x, int n)
{
    double low, high;
    if (x >= 0 && x <= 1)
    {
        low = x;
        high = 1;
    }
    else
    {
        low = 1;
        high = x;
    }
    double epsilon = 0.00000001;
    double guess = (high + low) / 2;
    cout << guess << endl;
    while (abs(pow(guess, n) - x) >= epsilon)
    {
        if (pow(guess, n) > x)
        {
            high = guess;
        }
        else
        {
            low = guess;
        }
        guess = (high + low) / 2;
        cout << guess << endl;
    }
    cout << fixed << setprecision(16) << guess;
}

int main()
{
    search(4, 2);
    return 0;
}