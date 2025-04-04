// you are given a sorted array. You have to find frequency of each element less than O(n) time complexity

// input: 14
// 1 1 1 2 3 3 5 5 8 8 8 9 9 10
#include <bits/stdc++.h>
using namespace std;
void findFrequency(int *arr, int left, int right, vector<int> &freqArray)
{
    // base case:: when the sorted array contains only one element
    if (arr[left] == arr[right])
    {
        freqArray[arr[left]] += right - left + 1;
        return;
    }
    int mid = left + (right - left) / 2;
    findFrequency(arr, left, mid, freqArray);
    findFrequency(arr, mid + 1, right, freqArray);
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
    // craete a vector of size of the maximum element of the array
    vector<int> freqArray(arr[n - 1] + 1, 0);
    findFrequency(arr, 0, n - 1, freqArray);
    for (int i = 1; i < freqArray.size(); i++)
    {
        cout << i << ": " << freqArray[i] << '\n';
    }
}