#include <bits/stdc++.h>
#define loop(i, a, b) for (int i = a; i < b; i++)
using namespace std;

int linear_search(int arr[], int value, int size)
{
    loop(i, 0, size)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {4, 40, 10, 3, 2};
    int x = 3;
    int n = sizeof(arr) / sizeof(int);
    int result = linear_search(arr, x, n);
    cout << result << endl;
    return 0;
}