/*
Given an array of N distinct integers, find floor value of input ‘key’. 
Say, A = {-1, 2, 3, 5, 6, 8, 9, 10} and key = 7, we should return 6 as outcome.
*/

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
    return start;
}

int floors(int arr[], int start, int end, int value)
{
    if (arr[end - 1] < value)
    {
        return arr[end - 1];
    }
    else if (arr[start] > value)
    {
        return -1;
    }
    else
    {
        return arr[u_binary_search(arr, start, end, value)];
    }
}

int main()
{
    int arr[] = {-1, 2, 3, 5, 6, 8, 9, 10};
    int x = 7;
    int n = sizeof(arr) / sizeof(int);
    int result = floors(arr, 0, n, x);
    cout << result << endl;
    return 0;
}