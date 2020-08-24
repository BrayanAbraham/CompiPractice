#include <bits/stdc++.h>
using namespace std;

int getRandom(int x, int y)
{
    srand(time(NULL));
    return (x + rand() % (y - x + 1));
}

int randomized_binary_search(int arr[], int start, int end, int value)
{
    while (end >= start)
    {
        int pos = getRandom(start, end);
        if (arr[pos] == value)
        {
            return pos;
        }
        else if (arr[pos] > value)
        {
            end = pos - 1;
        }
        else
        {
            start = pos + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int x = 4;
    int n = sizeof(arr) / sizeof(int);
    int result = randomized_binary_search(arr, 0, n, x);
    cout << result << endl;
    return 0;
}