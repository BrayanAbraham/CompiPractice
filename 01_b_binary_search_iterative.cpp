#include <bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int start, int end, int value)
{
    while (end >= start)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == value)
        {
            return mid;
        }
        else if (arr[mid] > value)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int x = 4;
    int n = sizeof(arr) / sizeof(int);
    int result = binary_search(arr, 0, n, x);
    cout << result << endl;
    return 0;
}