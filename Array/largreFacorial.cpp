#include <iostream>
#include <vector>
using namespace std;

vector<int> multiply(vector<int> a, int b) // we will calculate a*b where
// a is a large integer expressed in vector form
{
    vector<int> c;
    long long carry = 0;
    for (int i = 0; i < a.size(); i++)
    {
        c.push_back((a.at(i) * b + carry) % 10);
        carry = (a.at(i) * b + carry) / 10;
    }
    while (carry)
    {
        c.push_back(carry % 10);
        carry /= 10;
    }
    // cancel the initial 0s that are at the end of the array
    while (c.at(c.size() - 1) == 0)
        c.pop_back();

    return c;
}
void showFactorial(int n)
{
    vector<int> a = {1};
    for (int i = 1; i <= n; i++)
    {
        a = multiply(a, i);
    }
    for (int i = a.size() - 1; i >= 0; i--)
    {
        cout << a.at(i);
    }
    cout << '\n';
}
int main()
{
    int n;
    cin >> n;
    showFactorial(n);
}