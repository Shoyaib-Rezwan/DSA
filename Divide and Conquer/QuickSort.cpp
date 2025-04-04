#include <bits/stdc++.h>
using namespace std;
int partition(int *arr, int p, int q)
{
    int left = p - 1;
    for (int i = p; i < q; i++)
    {
        if (arr[i] <= arr[q])
        {
            swap(arr[++left], arr[i]);
        }
    }
    swap(arr[++left], arr[q]);
    return left;
}
void quickSort(int *arr, int p, int q)
{
    if (p >= q)
        return;
    int partitionIndex = partition(arr, p, q);
    quickSort(arr, p, partitionIndex - 1);
    quickSort(arr, partitionIndex + 1, q);
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
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
}