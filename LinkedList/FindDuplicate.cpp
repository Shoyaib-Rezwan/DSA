// https://medium.com/@simrangarg0501/finding-the-duplicate-number-using-floyds-tortoise-and-hare-algorithm-618ced80e98e
// floyd's cycle detection algorithm
#include <iostream>
using namespace std;
int findDuplicate(int *arr)
{
    int tortoise = arr[0];
    int hare = arr[0];
    // determine the existence of cycle
    do
    {
        tortoise = arr[tortoise];
        hare = arr[arr[hare]];
    } while (tortoise != hare);
    // move tortoise at the beginning and move both at the same pace
    tortoise = arr[0];
    while (tortoise != hare)
    {
        tortoise = arr[tortoise];
        hare = arr[hare];
    }
    return tortoise;
}
int main()
{
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << findDuplicate(arr);
}