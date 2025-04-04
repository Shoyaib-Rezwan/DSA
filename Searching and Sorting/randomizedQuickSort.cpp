#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void randomizedQuickSort(int *arr, int first, int last)
{
    if (first >= last)
        return;
    int pivotpos = first + rand() % (last - first + 1); // randomly generating the pivot position
    swap(arr[pivotpos], arr[last]);                     // transfering the pivot to the last of the array
    int pivot = arr[last];
    int i = first - 1;
    int temp;
    for (int j = first; j <= last - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    int partition = i + 1;
    swap(arr[last], arr[partition]);
    randomizedQuickSort(arr, first, partition - 1);
    randomizedQuickSort(arr, partition + 1, last);
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
    randomizedQuickSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << '\t';
    }
    cout << '\n';
    clock_t end = clock();
    cout << (end - start) / (double)CLOCKS_PER_SEC << " s";
}