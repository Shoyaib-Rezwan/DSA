/*
Suppose you are given n numbers. Generate all its subsets.
time complexity:O(2^n)
space complexity:O(n*(2^n))

**this is a beautiful example of bitmask.
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> generateSubsets(vector<int> &nums)
{
    // 2D vector for storing the subsets
    vector<vector<int>> subsets;
    int n = nums.size();
    // mask's value will be varied from 0 to 2^n-1
    for (int mask = 0; mask < (1 << n); mask++)
    {
        vector<int> subset;
        // Now track which of the n values from the nums will be included in the subset
        for (int i = 0; i < n; i++)
        {
            // if the i-th index of mask is 1 then push it in the subset
            if (mask & (1 << i))
            {
                subset.push_back(nums[i]);
            }
        }
        subsets.push_back(subset);
    }
    return subsets;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<vector<int>> subsets = generateSubsets(nums);
    for (vector<int> subset : subsets)
    {
        for (int i = 0; i < subset.size(); i++)
        {
            cout << subset[i] << ' ';
        }
        cout << "\n";
    }
}