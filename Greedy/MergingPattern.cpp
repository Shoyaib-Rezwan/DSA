// Suppose you are given n sorted arrays of different lengths. Now find minimum cost of merging then together into a single sorted array. Cost of merging 2 arrays of length p and q is p+q
/*
    input: 6 5 2 3
    output: 31
*/
#include <bits/stdc++.h>
using namespace std;
int findMinCost(vector<int> &lenghts)
{
    int cost = 0;
    // first store the array lengths into a minmum heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int x : lenghts)
    {
        minHeap.push(x);
    }
    // continue merging until all the arrays are mergwd into a single array
    while (minHeap.size() > 1)
    {
        // each time choose the smallest two arrays, merge them together and pushed them back into the heap
        int a = minHeap.top();
        minHeap.pop();
        int b = minHeap.top();
        minHeap.pop();
        int c = a + b; // let c be the merged form of a and b arrays. Lenghts of it will be a+b so will be the cost of merging them
        cost += c;
        minHeap.push(c);
    }
    return cost;
}
int main()
{
    int n;
    cin >> n;
    vector<int> lengths; // it will contain lengths of n arrays
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        lengths.push_back(data);
    }
    cout << findMinCost(lengths);
}