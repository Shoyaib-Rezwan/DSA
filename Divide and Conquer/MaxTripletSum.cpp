#include <bits/stdc++.h>
using namespace std;
int findMaxTripletSum(int *arr, int p, int r)
{
    if (r - p < 2)
        return INT32_MIN;
    if (r - p == 2)
        return arr[p] + arr[p + 1] + arr[p + 2];
    int mid = p + (r - p) / 2;
    int separateSum = max(findMaxTripletSum(arr, p, mid), findMaxTripletSum(arr, mid + 1, r));
    int overLapSum = max(arr[mid - 1] + arr[mid] + arr[mid + 1], arr[mid] + arr[mid + 1] + arr[mid + 2]);
    return max(separateSum, overLapSum);
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
    cout << findMaxTripletSum(arr, 0, n - 1);
}