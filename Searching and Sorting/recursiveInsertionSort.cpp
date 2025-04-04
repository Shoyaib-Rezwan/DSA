#include <iostream>
void recursiveInsertionSort(int *arr, int i, int n) // i=current index
// n=sizeofthearray
{
    if (i >= n)
        return;
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
    recursiveInsertionSort(arr, i + 1, n);
}
using namespace std;
int main()
{
    int arr[] = {5, 7, 7, 8, 1, 2, 6, 7, 8, 9};
    recursiveInsertionSort(arr, 0, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << arr[i] << '\t';
    }
}