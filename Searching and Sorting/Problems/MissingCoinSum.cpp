/*
Time limit: 1.00 s
Memory limit: 512 MB



You have n coins with positive integer values. What is the smallest sum you cannot create using a subset of the coins?
Input
The first input line has an integer n: the number of coins.
The second line has n integers x_1,x_2,\dots,x_n: the value of each coin.
Output
Print one integer: the smallest coin sum.
Constraints

1 <= n <= 2*10^5
1 <= x_i <= 10^9

Example
Input:
5
2 9 1 2 7

Output:
6
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int x[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    sort(x, x + n);
    long long missingNum = 1, i = 0;
    while (i < n)
    {
        if (x[i] > missingNum)
            break;
        else
            missingNum += x[i++];
    }
    cout << missingNum;
}