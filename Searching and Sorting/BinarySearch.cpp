#include <iostream>
#include <vector>
using namespace std;
int iterativeBinarySearch(vector<int> &A, int key)
{
    int left = 0, right = A.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (A[mid] == key)
            return mid;
        else if (A[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}
int recursiveBinarySearch(vector<int> &A, int key, int left, int right)
{
    if (left > right)
        return -1;
    int mid = (left + right) / 2;
    if (A.at(mid) == key)
        return mid;
    else if (A.at(mid) > key)
        return recursiveBinarySearch(A, key, left, mid - 1);
    else
        return recursiveBinarySearch(A, key, mid + 1, right);
}
int main()
{
    vector<int> A;
    for (int i = 0; i < 8; i++)
    {
        A.push_back(i + 1);
    }

    for (int i = 0; i < 11; i++)
    {
        cout << recursiveBinarySearch(A, i + 1, 0, A.size() - 1) << '\t';
    }
}