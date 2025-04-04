/*
suppose you are given an long longeger array. You have to return the subarray with maximum sum.
If there are multiple subarrays with maximum sum then return the subarray wth minimum length

Input:
8
[6, 3, -10, 3, -2, 5, -1, 4]
Output:
[6, 3] with a sum of 9.
*/

#include <bits/stdc++.h>
using namespace std;
vector<long long> findOverlappedSum(long long *arr, long long p, long long r) // this function finds the maximum sum that passes through the mid
{
    vector<long long> result;
    long long maxSum = INT32_MIN;
    long long sum = 0;
    long long mid = p + (r - p) / 2;
    long long leftIndex;
    // finding maxSum from mid to left
    for (long long i = mid; i >= p; i--)
    {
        sum += arr[i];
        if (sum > maxSum)
        {
            maxSum = sum;
            leftIndex = i;
        }
    }
    long long leftSum = maxSum;
    sum = 0;
    maxSum = INT32_MIN;
    long long rightIndex;
    // finding maxSum from mid+1 to right
    for (long long i = mid + 1; i <= r; i++)
    {
        sum += arr[i];
        if (sum > maxSum)
        {
            maxSum = sum;
            rightIndex = i;
        }
    }
    return {leftIndex, rightIndex, leftSum + maxSum};
}
void getDesiredSubArray(vector<long long> &v1, vector<long long> &v2)
{
    if (v1[2] > v2[2] || v1[2] == v2[2] && v1[1] - v1[0] < v2[1] - v2[0])
    {
        v2[0] = v1[0];
        v2[1] = v1[1];
        v2[2] = v1[2];
    }
}
// returned vector will contain the left index, right index and sum of the subarray
vector<long long> findMaximumSubarraySum(long long *arr, long long p, long long r)
{
    if (p > r)
        return {-1, -2, 0};
    if (p == r)
        return {p, r, arr[p]};
    long long mid = p + (r - p) / 2;
    vector<long long> leftSubArray = findMaximumSubarraySum(arr, p, mid);
    vector<long long> rightSubArray = findMaximumSubarraySum(arr, mid + 1, r);
    vector<long long> overLappedSubarray = findOverlappedSum(arr, p, r);
    getDesiredSubArray(leftSubArray, overLappedSubarray);
    getDesiredSubArray(rightSubArray, overLappedSubarray);
    if (overLappedSubarray[2] < 0)
    {
        return {-1, -2, 0};
    }
    return overLappedSubarray;
}
int main()
{
    long long n;
    cin >> n;
    long long *arr = new long long[n];
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<long long> result = findMaximumSubarraySum(arr, 0, n - 1);
    cout << "[";
    for (long long i = result[0]; i <= result[1]; i++)
    {
        cout << arr[i];
        if (i + 1 <= result[1])
        {
            cout << ", ";
        }
    }
    cout << "] with a sum " << result[2];
}