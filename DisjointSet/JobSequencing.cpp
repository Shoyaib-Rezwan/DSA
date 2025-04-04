// https://www.geeksforgeeks.org/job-sequencing-problem-using-disjoint-set/
/*
Input: Four Jobs with following deadlines and profits
JobID Deadline Profit
   a      4      20
   b      1      10
   c      1      40
   d      1      30
Output: Following is maximum profit sequence of jobs:
       c, a

Input: Five Jobs with following deadlines and profits
JobID Deadline Profit
   a     2       100
   b     1       19
   c     2       27
   d     1       25
   e     3       15
Output: Following is maximum profit sequence of jobs:
       c, a, e
*/

/***********************This method solves problem by just sorting*************************/
// #include <bits/stdc++.h>
// using namespace std;
// struct Job
// {
//     int id, deadline, profit;
// };
// struct comparator
// {
//     bool operator()(Job &a, Job &b)
//     {
//         return a.profit > b.profit;
//     }
// };
// pair<int, vector<int>> getJobSequence(Job *jobs, int n, int &maxDeadline)
// {
//     // sort the jobs in descending order based on profit
//     sort(jobs, jobs + n, comparator());
//     vector<int> slots(maxDeadline + 1, -1); // slots is the vector from 0 to maxdeadline representing time. slots[i] contains the id of the work to be done at time i
//     int maxProfit = 0;
//     // traverse the jobs in descending order
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = jobs[i].deadline; j > 0; j--)
//         {
//             if (slots[j] == -1)
//             {
//                 slots[j] = jobs[i].id;
//                 maxProfit += jobs[i].profit;
//                 break;
//             }
//         }
//     }
//     // vector that contains the sequece of the work to be done
//     vector<int> result;
//     for (int i = 1; i <= maxDeadline; i++)
//     {
//         if (slots[i] != -1)
//             result.push_back(slots[i]);
//     }
//     return {maxProfit, result};
// }
// int main()
// {
//     int n;
//     cin >> n;
//     Job *jobs = new Job[n];
//     int maxDeadline = 0;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
//         maxDeadline = max(maxDeadline, jobs[i].deadline);
//     }
//     pair<int, vector<int>> jobSequence = getJobSequence(jobs, n, maxDeadline);
//     cout << "Max profit: " << jobSequence.first << "\n"
//          << "The job sequence: ";
//     for (int x : jobSequence.second)
//     {
//         cout << x << ' ';
//     }
// }

/*************Solving using disjoint set data structure****************/
#include <bits/stdc++.h>
using namespace std;
struct Job
{
    int id, deadline, profit;
    Job(int id, int deadline, int profit)
    {
        this->id = id;
        this->deadline = deadline;
        this->profit = profit;
    }
};
class DisjointSet
{
    int *parent;
    int n;

public:
    DisjointSet(int n)
    {
        this->n = n;
        parent = new int[n];
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    // FINDSET with path compression
    int findSet(int x)
    {
        if (parent[x] != x)
            parent[x] = findSet(parent[x]);
        return parent[x];
    }
    // the UNION doesn't have the union rank heuristic
    // input the values carefully because its always the case that y's parent will also be the parent of the whole union set
    void unionSet(int x, int y)
    {
        parent[x] = parent[y];
    }
};
// comperator for sorting the jobs in descending order based on the profit
struct comperator
{
    bool operator()(Job &a, Job &b)
    {
        return a.profit > b.profit;
    }
};
pair<int, vector<int>> getJobSequence(vector<Job> &jobs, int maxDeadline)
{
    // each member of the DSU will be a set with an empty slot
    DisjointSet obj(maxDeadline + 1);
    // sort the jobs in descending order based on profit
    sort(jobs.begin(), jobs.end(), comperator());
    int maxProfit = 0;
    vector<int> jobIds; // it will store which jobs should be done
    for (int i = 0; i < jobs.size(); i++)
    {
        int slot = obj.findSet(jobs[i].deadline);
        if (slot != 0)
        {
            maxProfit += jobs[i].profit;
            obj.unionSet(slot, slot - 1);
            jobIds.push_back(jobs[i].id);
        }
    }
    return {maxProfit, jobIds};
}
int main()
{
    int n;
    cin >> n;
    vector<Job> jobs;
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        int id, deadline, profit;
        cin >> id >> deadline >> profit;
        jobs.push_back(*(new Job(id, deadline, profit)));
        maxDeadline = max(maxDeadline, deadline);
    }
    pair<int, vector<int>> jobSequence = getJobSequence(jobs, maxDeadline);
    cout << "Max Profit: " << jobSequence.first << '\n';
    cout << "Jobs to be done: ";
    for (int x : jobSequence.second)
    {
        cout << x << ' ';
    }
}