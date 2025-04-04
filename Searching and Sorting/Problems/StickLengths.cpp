// https://cses.fi/problemset/task/1074
/*
Time limit: 1.00 s
Memory limit: 512 MB
There are n sticks with some lengths. Your task is to modify the sticks so that each stick has the same length.
You can either lengthen and shorten each stick. Both operations cost x where x is the difference between the new and original length.
What is the minimum total cost?
Input
The first input line contains an integer n: the number of sticks.
Then there are n integers: p_1,p_2,\ldots,p_n: the lengths of the sticks.
Output
Print one integer: the minimum total cost.
Constraints

1 <= n <= 2* 10^5
1 <= p_i <= 10^9

Example
Input:
5
2 3 1 5 2

Output:
5*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    sort(p, p + n);
    int median = (n % 2) ? p[n / 2] : (p[n / 2] + p[n / 2 - 1]) / 2;
    long long cost = 0;
    for (int i = 0; i < n; i++)
    {
        cost = cost + abs(median - p[i]);
    }
    cout << cost;
}