/*suppose you are given an array. You have to find its peak. A peak of an array is the element that is not smaller than its neighbours. If there are multiple peaks then output any one of them*/

#include <bits/stdc++.h>
using namespace std;
int findPeak(int *arr, int p, int r)
{
    if (p > r)
        return INT32_MIN;
    if (p == r)
        return arr[p];
    int mid = p + (r - p) / 2;
    int left = findPeak(arr, p, mid - 1);
    int right = findPeak(arr, mid + 1, r);
    return max(max(arr[mid], left), right);
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << findPeak(arr, 0, n - 1);
}