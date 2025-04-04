#include <iostream>
using namespace std;
void heapify(int *arr, int i, int heapSize)
{
    // cout << "Hello\n";
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;
    if (left <= heapSize && arr[largest] < arr[left])
        largest = left;
    if (right <= heapSize && arr[largest] < arr[right])
        largest = right;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, largest, heapSize);
    }
}
void buildHeap(int *arr, int heapSize)
{
    int i;
    for (i = heapSize / 2; i >= 1; i--)
    {

        heapify(arr, i, heapSize);
    }
}
void heapSort(int *arr, int *begin, int *end)
{
    int *heap, i = 1;
    int heapSize = end - begin + 1;
    heap = new int[heapSize + 1];
    int *start = begin;
    while (begin != end)
    {
        heap[i++] = *begin;
        begin++;
    }
    heap[i] = *end;
    buildHeap(heap, heapSize);
    int temp = heapSize;
    while (temp)
    {
        swap(heap[1], heap[temp--]);
        heapify(heap, 1, temp);
    }
    begin = start;
    i = 1;
    while (begin != end)
    {
        *begin = heap[i++];
        begin++;
    }
    *end = heap[i];
    delete heap;
}
int main()
{
    int size;
    cin >> size;
    // srand(time(NULL));
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
    heapSort(arr, arr + 3, arr + size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << '\t';
    }
}