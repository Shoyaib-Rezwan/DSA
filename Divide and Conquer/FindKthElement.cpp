/*
suppose you are given to sorted array. You have to find the Kth element if the two sorted array were to merge
*/
#include <bits/stdc++.h>
using namespace std;
int findKthElement(int *arr1, int i1, int *arr2, int i2, int k, int n1, int n2) // i1, i2 current element of interest in arr1 and arr2 reespectively
{
    if (k == 1)
    {
        if (i1 < n1 && i2 < n2)
        {
            return min(arr1[i1], arr2[i2]);
        }
        else if (i1 < n1)
            return arr1[i1];
        else
            return arr2[i2];
    }
    if (arr1[i1] < arr2[i2])
        return findKthElement(arr1, i1 + 1, arr2, i2, k - 1, n1, n2);
    else
        return findKthElement(arr1, i1, arr2, i2 + 1, k - 1, n1, n2);
}
int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    int *arr1 = new int[n1];
    int *arr2 = new int[n2];
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }
    cout << findKthElement(arr1, 0, arr2, 0, 5, n1, n2);
}