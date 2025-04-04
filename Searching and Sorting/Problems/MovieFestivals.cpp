// https://cses.fi/problemset/task/1629
/*
In a movie festival n movies will be shown. You know the starting and ending time of each movie. What is the maximum number of movies you can watch entirely?
Input
The first input line has an integer n: the number of movies.
After this, there are n lines that describe the movies. Each line has two integers a and b: the starting and ending times of a movie.
Output
Print one integer: the maximum number of movies.
Constraints

1 <= n <= 2* 10^5
1 <= a < b <= 10^9

Example
Input:
5
3 5
4 9
5 8
6 8
9 10
Output:
3
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<long long, long long>> a(n);
    for (int i = 0; i < n; i++)
    {
        long long x, y;
        cin >> x >> y;
        a[i] = make_pair(y, x);
    }
    sort(a.begin(), a.end());
    int count = 0;
    long long lastWatched = INT32_MIN; // contains the ending time of the last watched movie
    for (int i = 0; i < n; i++)
    {
        if (a[i].second >= lastWatched)
        {
            count++;
            lastWatched = a[i].first;
        }
    }
    cout << count;
}