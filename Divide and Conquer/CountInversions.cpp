/*
    Suppose you are guven an array A. Count all the inversions. Two elements in the array are inverted if arr[i]>arr[j] but i<j
*/
#include <bits/stdc++.h>
using namespace std;
int merge(vector<int> &arr, int p, int q, int r)
{
    int count = 0;
    int nL = q - p + 1;
    int nR = r - q;
    vector<int> L(nL), R(nR);
    for (int i = 0; i < nL; i++)
    {
        L[i] = arr[p + i];
    }
    for (int i = 0; i < nR; i++)
    {
        R[i] = arr[q + 1 + i];
    }
    int i = 0, j = 0, k = p;
    while (i < nL && j < nR)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            count += (nL - i);
        }
        k++;
    }
    while (i < nL)
        arr[k++] = L[i++];
    while (j < nR)
        arr[k++] = R[j++];
    return count;
}
int mergeSort(vector<int> &arr, int p, int r)
{
    if (p >= r)
        return 0;
    int count = 0;
    int mid = (p + r) / 2;
    count += mergeSort(arr, p, mid);
    count += mergeSort(arr, mid + 1, r);
    count += merge(arr, p, mid, r);
    return count;
}

int main()
{
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        arr.push_back(data);
    }
    cout << mergeSort(arr, 0, n - 1);
}