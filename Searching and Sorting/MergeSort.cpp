// see chapter 2.3 of introduction to algorithms by cormen to get idea of this code
#include <iostream>
using namespace std;
template <typename X>
class MergeSort
{
    X *arr;
    int size;

public:
    MergeSort(int n)
    {
        this->size = n;
        arr = new X[n];
    }
    void input()
    {
        cout << "Input " << size << " elements::\n";
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }
    void show()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << '\t';
        }
    }
    void Merge(int p, int q, int r);
    void sort()
    {
        MergeSortMain(0, size - 1);
    }
    void MergeSortMain(int p, int r);
};
template <typename X>
void MergeSort<X>::Merge(int p, int q, int r)
{
    int nL = q - p + 1;
    int nR = r - q;
    X *L = new X[nL];
    X *R = new X[nR];
    int i, j, k;
    for (i = 0; i < nL; i++)
    {
        L[i] = arr[p + i];
    }
    for (j = 0; j < nR; j++)
    {
        R[j] = arr[q + 1 + j];
    }
    i = 0;
    j = 0;
    k = p;
    while (i < nL && j < nR)
    {
        if (L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < nL)
    {
        arr[k] = L[i++];
        k++;
    }
    while (j < nR)
    {
        arr[k] = R[j++];
        k++;
    }
    delete[] L;
    delete[] R;
}
template <typename X>
void MergeSort<X>::MergeSortMain(int p, int r)
{
    if (p >= r)
        return;
    int mid = (p + r) / 2;
    MergeSortMain(p, mid);
    MergeSortMain(mid + 1, r);
    Merge(p, mid, r);
}
int main()
{
    MergeSort<int> m(10);
    m.input();
    m.sort();
    m.show();
}