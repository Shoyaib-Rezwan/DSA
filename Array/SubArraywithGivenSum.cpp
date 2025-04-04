// Given a 1-based indexing array arr[] of integers and an integer sum. You mainly need to return the left and right indexes(1-based indexing) of that subarray. In case of multiple subarrays, return the subarray indexes which come first on moving from left to right. If no such subarray exists return an array consisting of element -1.
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s)
    {
        int l = 0, r = 0;
        long long sum = arr[l];
        while (r < n)
        {
            if (sum == s)
                break;
            else if (sum > s)
            {
                l++;
                sum -= arr[l - 1];
                if (l > r) // cause left can't be before r
                {
                    r++;
                    sum = arr[r];
                }
            }
            else
            {
                r++;
                sum += arr[r];
            }
        }
        vector<int> result;
        if (r == n)
            result.push_back(-1);
        else
        {
            result.push_back(l + 1);
            result.push_back(r + 1);
        }
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long s;
        cin >> n >> s;
        vector<int> arr(n);
        // int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends