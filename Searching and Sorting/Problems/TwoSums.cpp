/*Time limit: 1.00 s
Memory limit: 512 MB



You are given an array of n integers, and your task is to find two values (at distinct positions) whose sum is x.
Input
The first input line has two integers n and x: the array size and the target sum.
The second line has n integers a_1,a_2,\dots,a_n: the array values.
Output
Print two integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.
Constraints

1 <= n <= 2*10^5
1 <= x,a_i <= 10^9

Example
Input:
4 8
2 7 5 1

Output:
2 4*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, temp;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a[i] = make_pair(temp, i + 1);
    }
    sort(a.begin(), a.end());
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (a[i].first + a[j].first == x)
        {
            cout << a[i].second << ' ' << a[j].second;
            break;
        }
        else if (a[i].first + a[j].first > x)
            j--;
        else
            i++;
    }
    if (i >= j)
        cout << "IMPOSSIBLE";
}