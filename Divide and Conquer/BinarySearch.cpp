#include <bits/stdc++.h>
using namespace std;
int findKeyinSortedArray(int *arr, int i, int j, int &key)
{
    if (i > j)
        return -1;
    int mid = i + (j - i) / 2; // use this instead if (i+j)/2 to avoid integer overflow
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] > key)
        return findKeyinSortedArray(arr, i, mid - 1, key);
    else
        return findKeyinSortedArray(arr, mid + 1, j, key);
}
int main()
{
    int n;
    cout << "Enter number of elements:: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter a sorted array:: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter key to search:: ";
        int key;
        cin >> key;
        cout << findKeyinSortedArray(arr, 0, n - 1, key);
    }
}