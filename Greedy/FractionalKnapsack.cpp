/*Given two arrays weight[] and profit[] the weights and profit of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item.
Input: weight[] = {10, 20, 30}, profit[] = {60, 100, 120}, W= 50

Output: Maximum profit earned = 240

Explanation:
Decreasing p/w ratio[] = {6, 5, 4}

Taking up the weight values 10, 20, (2 / 3) * 30
Profit = 60 + 100 + 120 * (2 / 3) = 240



Input: weight[] = {10, 40, 20, 24}, profit[] = {100, 280, 120, 120}, W = 60

Output: Maximum profit earned = 440

Explanation:
Decreasing p/w ratio[] = {10, 7, 6, 5}

Taking up the weight values 10, 40, (1 / 2) * 120
Profit = 100 + 280 + (1 / 2) * 120 = 440
*/
#include <bits/stdc++.h>
using namespace std;
// functor for sorting the vector of pairs in descending order of profit/weight
struct comperator
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        double r1 = (double)a.first / a.second;
        double r2 = (double)b.first / b.second;
        return r1 > r2;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> items(n); //(profit,weight)
    for (int i = 0; i < n; i++)
    {
        // take input of the profits
        cin >> items[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        // take input of the weights
        cin >> items[i].second;
    }
    int maxWeight;
    cin >> maxWeight;
    sort(items.begin(), items.end(), comperator());
    float maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        // if the available weight is larger then take the whole item
        if (maxWeight >= items[i].second)
        {
            maxWeight -= items[i].second;
            maxProfit += items[i].first;
        }
        // if the available weight is smaller then take only the necessary portion of it and break out of the loop
        else
        {
            maxProfit += maxWeight * ((double)items[i].first / items[i].second);
            break;
        }
    }
    cout << maxProfit;
}