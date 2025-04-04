// you are given an array of integers. Find its min using DnC
// 7
// 12 14 18 -9 15 -15 -15
// output -15
#include <bits/stdc++.h>
using namespace std;
int findMin(int *arr, int left, int right)
{
    if (left == right)
        return arr[left];
    int mid = left + (right - left) / 2;
    return min(findMin(arr, left, mid), findMin(arr, mid + 1, right));
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
    cout << findMin(arr, 0, n - 1);
}