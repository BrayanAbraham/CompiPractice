/*
Catalan numbers are a sequence of natural numbers that occurs in many interesting counting
problems like following.
    1) Count the number of expressions containing n pairs of parentheses which are correctly
    matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).
    2) Count the number of possible Binary Search Trees with n keys
    3) Count the number of full binary trees (A rooted binary tree is full if every vertex 
    has either two children or no children) with n+1 leaves.
    4) Given a number n, return the number of ways you can draw n chords in a circle with 
    2 x n points such that no 2 chords intersect.
The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …
*/
#include <bits/stdc++.h>
#define loop(i, a, b) for (int i = a; i < b; i++)
using namespace std;

int catalan(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        unsigned long int c = 0;
        loop(i, 0, n)
        {
            c += catalan(i) * catalan(n - i - 1);
        }
        return c;
    }
}

int main()
{
    int n;
    cin >> n;
    cout << catalan(n);
    return 0;
}