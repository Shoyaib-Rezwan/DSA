#include <bits/stdc++.h>
using namespace std;
void merge(int *arr, int p, int q, int r)
{
    int *left = new int[q - p + 1];
    int *right = new int[r - q];
    for (int i = p; i <= q; i++)
    {
        left[i - p] = arr[i];
    }
    for (int i = q + 1; i <= r; i++)
    {
        right[i - q - 1] = arr[i];
    }
    int i = 0, j = 0;
    while (i < q - p + 1 && j < r - q)
    {
        if (left[i] < right[j])
        {
            arr[i + j + p] = left[i++];
        }
        else
        {
            arr[i + j + p] = right[j++];
        }
    }
    while (i < q - p + 1)
    {
        arr[i + j + p] = left[i++];
    }
    while (j < r - q)
    {
        arr[i + j + p] = right[j++];
    }
    delete[] left;
    delete[] right;
}
void mergeSort(int *arr, int i, int r)
{
    if (i >= r)
        return;
    int mid = i + (r - i) / 2;
    mergeSort(arr, i, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, i, mid, r);
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
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
}