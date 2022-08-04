#include <bits/stdc++.h>
#define loop(i, a, b) for (int i = a; i < b; i++)
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    loop(j, low, high)
    {
        if (arr[j] < pivot)
        {
            i++;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    int t = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = t;
    return i + 1;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
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
    quicksort(arr, 0, n - 1);
    loop(i, 0, n)
    {
        cout << arr[i] << " ";
    }
    return 0;
}