// https://cses.fi/problemset/task/1619
/*
Time limit: 1.00 s
Memory limit: 512 MB



You are given the arrival and leaving times of n customers in a restaurant.
What was the maximum number of customers in the restaurant at any time?
Input
The first input line has an integer n: the number of customers.
After this, there are n lines that describe the customers. Each line has two integers a and b: the arrival and leaving times of a customer.
You may assume that all arrival and leaving times are distinct.
Output
Print one integer: the maximum number of customers.
Constraints

1 <= n <= 2*10^5
1 <= a < b <= 10^9

Example
Input:
3
5 8
2 4
3 9

Output:
2

*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    int i = 0, j = 0, currentCustomers = 0, maxCustomers = 0;
    while (i < n)
    {
        if (a[i] < b[j])
        {
            currentCustomers++;
            maxCustomers = max(maxCustomers, currentCustomers);
            i++;
        }
        else if (a[i] > b[j])
        {
            currentCustomers--;
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    cout << maxCustomers;
}