// suppose you are given 2 n size arrays. The 1st array represents the starting times of n tasks and the 2nd array represent their ending times.Assume you can start a task immediately after ending a previous task. Now find out the maximum amount of tasks you can perform...
/*
input: 7
[0 1 3 5 5 7 8]
[6 2 4 7 9 8 9]

output:
Activity started at: 1 and ends at  2
Activity started at: 3 and ends at  4
Activity started at: 5 and ends at  7
Activity started at: 7 and ends at  8
Activity started at: 8 and ends at  9
*/
#include <bits/stdc++.h>
using namespace std;
struct comperator
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second < b.second;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> tasks(n); //(start,end)
    // take input of the starting times
    for (int i = 0; i < n; i++)
    {
        cin >> tasks[i].first;
    }
    // take input of the ending times
    for (int i = 0; i < n; i++)
    {
        cin >> tasks[i].second;
    }
    // sort all the tasks according to the ascending order of the ending time of the tasks
    sort(tasks.begin(), tasks.end(), comperator());
    // creating a doAbleTasks vector to store the tasks.Always insert the task that ends at the first
    vector<pair<int, int>> doAbleTasks;
    doAbleTasks.push_back(tasks[0]);
    int lastEndTime = doAbleTasks[0].second; // storing the last completed task's finishing time
    for (int i = 1; i < n; i++)
    {
        // store the task if it starts after the lastEndTime
        if (tasks[i].first >= lastEndTime)
        {
            doAbleTasks.push_back(tasks[i]);
            lastEndTime = tasks[i].second;
        }
    }
    for (pair<int, int> x : doAbleTasks)
    {
        cout << "Activity starts: " << x.first << "  Activity ends: " << x.second << "\n";
    }
}