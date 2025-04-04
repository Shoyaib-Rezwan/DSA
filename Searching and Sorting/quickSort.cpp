#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void quickSort(int *arr, int first, int last)
{
    // don't do anything if the array contains only one element
    if (first == last)
        return;
    int pivot = arr[last]; // setting pivot as the last element of the array
    int i = first - 1;
    for (int j = first; j <= last - 1; j++) // traverse from the arr[first] to arr[last-1] element of the array
    {
        // this portion is the crucial part for partitioning
        if (arr[j] <= pivot)
        {
            i = i + 1;
            swap(arr[i], arr[j]); // gathering all elements not greater that the pivot at the 1st part of the array
        }
    }
    swap(arr[i + 1], arr[last]);
    int partition = i + 1;
    // now the pivot at the partition is at the correct position
    // the array elements are now in this pattern: [portion-1:elements not greater than pivot][pivot][portion-2:elements not less than pivot]
    // checking exeistence of the portion 1 and recursively sorting it
    if (partition - 1 >= first)
        quickSort(arr, first, partition - 1);
    // checking exeistence of the portion 2 and recursively sorting it
    if (partition + 1 <= last)
        quickSort(arr, partition + 1, last);
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