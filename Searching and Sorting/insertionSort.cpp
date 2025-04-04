#include <iostream>
using namespace std;
void insertionSort(int *arr, int *begin, int *end)
{
    int left = begin - arr;
    int right = end - arr;
    int key, j, i;
    for (i = left + 1; i <= right; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    // clock_t start = clock();
    int size;
    cin >> size;
    // srand(time(NULL));
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
    insertionSort(arr, arr + 10, arr + size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << '\t';
    }
    cout << '\n';
    // clock_t end = clock();
    // cout << (end - start) / (double)CLOCKS_PER_SEC << " s";
}