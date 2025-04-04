#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int maxProduct = INT32_MIN, minProduct = INT32_MAX, productHere = 1;
    for (int i = 0; i < n; i++)
    {
        productHere *= arr[i];
        maxProduct = (arr[i] < 0) ? max(maxProduct, productHere) : arr[i];
        minProduct() if (!productHere)
            productHere = 1;
    }
    cout << maxProduct;
}