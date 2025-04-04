/* you are given an array. In this array every element appears in pair.But there will be a single element that will not be in pair. You have to find that element.
Hint: Before the appearing of the unpaired element in the array, all paired element will be in the previous even and consecutive odd number index.But after it appears then the order will be changed
*/
#include <bits/stdc++.h>
using namespace std;
int findUnpairedElement(int *arr, int p, int r)
{
    if (p == r)
        return arr[p];
    int mid = p + (r - p) / 2;
    if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) // you don't have to think about mid-1 and mid+1's existence because arr size will be atleast 3
        return arr[mid];
    if (mid % 2 == 0) // when mid is even
    {
        if (arr[mid + 1] == arr[mid]) // before the unpaired element 2*n and 2*n+1 are paired
            return findUnpairedElement(arr, mid + 2, r);
        else
            return findUnpairedElement(arr, p, mid - 2);
    }
    else
    {
        if (arr[mid] == arr[mid - 1])
            return findUnpairedElement(arr, mid + 1, r);
        else
            return findUnpairedElement(arr, p, mid - 1);
    }
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
    cout << findUnpairedElement(arr, 0, n - 1);
}