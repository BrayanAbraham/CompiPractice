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

unsigned long int binomial(unsigned int n, unsigned int k)
{
    unsigned long int res = 1;
    if (k > n - k)
    {
        k = n - k;
    }
    loop(i, 0, k)
    {
        res *= n - i;
        res /= i + 1;
    }
    return res;
}

unsigned long int catalan(unsigned int n)
{
    return binomial(2 * n, n) / (n + 1);
}

int main()
{
    int n;
    cin >> n;
    cout << catalan(n);
    return 0;
}