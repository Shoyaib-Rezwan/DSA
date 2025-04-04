// https://cses.fi/problemset/task/2216
/*
Time limit: 1.00 s
Memory limit: 512 MB
You are given an array that contains each number between 1... n exactly once. Your task is to collect the numbers from 1 to n in increasing order.
On each round, you go through the array from left to right and collect as many numbers as possible. What will be the total number of rounds?
Input
The first line has an integer n: the array size.
The next line has n integers x_1,x_2,...x_n: the numbers in the array.
Output
Print one integer: the number of rounds.
Constraints

1 <= n <= 2* 10^5

Example
Input:
5
4 2 1 5 3

Output:
3
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, temp, rounds = 1;
    cin >> n;
    vector<pair<int, int>> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        x[i] = make_pair(temp, i + 1);
    }
    sort(x.begin(), x.end());
    for (int i = 0; i < n - 1; i++)
    {
        if (x[i].second > x[i + 1].second)
            rounds++;
    }
    cout << rounds;
}