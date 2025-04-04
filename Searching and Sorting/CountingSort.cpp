// Write the counting sort. Your sorting algorithm must be stable
#include <bits/stdc++.h>
using namespace std;
vector<int> countingSort(vector<int> &nums, int k)
{
    vector<int> count(k + 1, 0);
    vector<int> arr(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        count[nums[i]]++;
    }
    for (int i = 1; i < k + 1; i++)
    {
        count[i] = count[i] + count[i - 1];
    }
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        arr[count[nums[i]] - 1] = nums[i];
        count[nums[i]]--;
    }
    return arr;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    nums = countingSort(nums, k);
    for (int x : nums)
    {
        cout << x << ' ';
    }
}