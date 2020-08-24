#include <bits/stdc++.h>
#define loop(i, a, b) for (int i = a; i < b; i++)
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
    int l1 = mid - start + 1;
    int l2 = end - mid;
    int L[l1], R[l2];
    loop(i, 0, l1)
    {
        L[i] = arr[start + i];
    }
    loop(i, 0, l2)
    {
        R[i] = arr[mid + 1 + i];
    }
    int x = 0, y = 0, k = start;
    while (x < l1 && y < l2)
    {
        if (L[x] < R[y])
        {
            arr[k] = L[x];
            x++;
        }
        else
        {
            arr[k] = R[y];
            y++;
        }
        k++;
    }

    while (x < l1)
    {
        arr[k] = L[x];
        x++;
        k++;
    }

    while (y < l2)
    {
        arr[k] = R[y];
        y++;
        k++;
    }
}

void mergesort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main()
{
    int arr[] = {55, 87, 20, 46, 9, 2, 0, 10, -5};
    int n = sizeof(arr) / sizeof(int);
    loop(i, 0, n)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    mergesort(arr, 0, n - 1);
    loop(i, 0, n)
    {
        cout << arr[i] << " ";
    }
    return 0;
}