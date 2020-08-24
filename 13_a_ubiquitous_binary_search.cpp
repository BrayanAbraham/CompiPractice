#include <bits/stdc++.h>
using namespace std;

int u_binary_search(int arr[], int start, int end, int value)
{
    while (end - start > 1)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] > value)
        {
            end = mid;
        }
        else
        {
            start = mid;
        }
    }

    if (arr[start] == value)
        return start;
    if (arr[end] == value)
        return end;
    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int x = 4;
    int n = sizeof(arr) / sizeof(int);
    int result = u_binary_search(arr, 0, n, x);
    cout << result << endl;
    return 0;
}