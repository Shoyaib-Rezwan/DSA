// Kadane's Algorithm
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *nums = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int maxSumHere = 0, maxSum = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        maxSumHere += nums[i];
        maxSum = max(maxSumHere, maxSum);
        if (maxSumHere < 0)
            maxSumHere = 0;
    }
    cout << maxSum;
}