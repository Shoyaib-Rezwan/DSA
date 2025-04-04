// separating the partition finding part from the quickSort()
// do this after completing quickSort.cpp
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;
int partition(int *arr, int first, int last)
{
    int pivot = arr[last];
    int i = first - 1;
    for (int j = first; j <= last - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[last]);
    return i + 1; // this is the partition
}
void quickSort(int *arr, int first, int last)
{
    if (first >= last)
        return;
    int partitionIndex = partition(arr, first, last);
    quickSort(arr, first, partitionIndex - 1);
    quickSort(arr, partitionIndex + 1, last);
}
int main()
{
    clock_t start = clock();
    int size;
    cin >> size;
    srand(time(NULL));
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
    quickSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << '\t';
    }
    cout << '\n';
    clock_t end = clock();
    cout << (end - start) / (double)CLOCKS_PER_SEC << " s";
}