// https: // www.geeksforgeeks.org/find-if-there-is-a-subarray-with-0-sum/

// // Given an array of positive and negative numbers, the task is to find if there is a subarray (of size at least one) with 0 sum.

// Examples :

//     Input : {4, 2, -3, 1, 6} Output : true Explanation : There is a subarray with zero sum from index 1 to 3.

//                                                          Input : {4, 2, 0, 1, 6} Output : true Explanation : The third element is zero.A single element is also a sub -
//     array.

//     Input : {-3, 2, 3, 1, 6} Output : false

// suppose you have an array of 10 elements. In it, a subArray from the index from 4 to 7 contains elements in such a way that there sum is 0. Then prefix sum till index-3 and index-7 will be same...
// another case is that if any index is directly 0 then that is the sunArray
#include <iostream>
#include <unordered_set>
using namespace std;
bool existsSubArray_Sum0(int *arr, int n)
{
    int prefixSum = 0;
    unordered_set<int> setSum;
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        if (setSum.find(prefixSum) != setSum.end() || !arr[i])
        {
            return true;
        }
        setSum.insert(prefixSum);
    }
    return false;
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
    cout << existsSubArray_Sum0(arr, n);
}