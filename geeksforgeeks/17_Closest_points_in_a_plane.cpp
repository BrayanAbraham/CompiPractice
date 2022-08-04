#include <bits/stdc++.h>
#define loop(i, a, b) for (int i = a; i < b; i++)
using namespace std;

class Point
{
public:
    int x, y;
};

int compareX(const void *a, const void *b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int compareY(const void *a, const void *b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}

float dist(Point p1, Point p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

float bruteForce(Point P[], int n)
{
    float min = FLT_MAX;
    loop(i, 0, n)
    {
        loop(j, i + 1, n)
        {
            float t = dist(P[i], P[j]);
            if (t < min)
            {
                min = t;
            }
        }
    }
    return min;
}

float stripClosest(Point strip[], int size, float d)
{
    float min = d;
    qsort(strip, size, sizeof(Point), compareY);
    loop(i, 0, size)
    {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; j++)
        {
            float t = dist(strip[i], strip[j]);
            if (t < min)
            {
                min = t;
            }
        }
    }
    return min;
}

float closestUtil(Point P[], int n)
{
    if (n <= 3)
    {
        return bruteForce(P, n);
    }

    int mid = n / 2;
    Point midPoint = P[mid];
    float dl = closestUtil(P, mid);
    float dr = closestUtil(P + mid, n - mid);
    float d = min(dl, dr);
    Point strip[n];
    int j = 0;
    loop(i, 0, n)
    {
        if (abs(P[i].x - midPoint.x) < d)
        {
            strip[j++] = P[i];
        }
    }
    return min(d, stripClosest(strip, j, d));
}

float closest(Point P[], int n)
{
    qsort(P, n, sizeof(Point), compareX);
    return closestUtil(P, n);
}

int main()
{
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}, {41, 2}};
    int n = sizeof(P) / sizeof(P[0]);
    cout << closest(P, n);
    return 0;
}