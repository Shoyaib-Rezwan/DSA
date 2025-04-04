#include <bits/stdc++.h>
using namespace std;
class Solution
{
    struct comperator
    {
        bool operator()(vector<int> &a, vector<int> &b)
        {
            return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]); // if two tasks have the same ending time then the task that has started earlier will come at first
        }
    };

public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        // sort the tasks according to their ending times
        sort(points.begin(), points.end(), comperator());
        // try to understand it by drawing diagram
        int count = 1;
        int endTime = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] <= endTime)
            {
                continue;
            }
            count++;
            endTime = points[i][1];
        }
        return count;
    }
};
