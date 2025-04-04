// Solve the system of the linear congruences::
// x = 1(mod2);
// x = 2(mod3);
// x = 3(mod5);
// x = 4(mod11);
// reference:: Rosen pg::301,problem 21
// answer:: 323
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    void FindInverse(int a, int b, int *x, int *y)
    {
        if (b == 0)
        {
            *x = 1;
            *y = 0;
        }
        else
        {
            int x1, y1;
            FindInverse(b, a % b, &x1, &y1);
            *x = y1;
            *y = x1 - (a / b) * y1;
        }
    }
    int ChineseRemainder(vector<int> &a, vector<int> &b) // vector 'a' contains the arbitary integers whereas vector 'b' contains all the moduli
    {
        int n = a.size(), i, m = 1, x = 0, inverse, temp;
        for (i = 0; i < n; i++)
        {
            m *= b.at(i);
        }
        for (i = 0; i < n; i++)
        {
            FindInverse(m / b.at(i), b.at(i), &inverse, &temp);
            if (inverse < 0)
                inverse += b.at(i);
            x += a.at(i) * (m / b.at(i)) * inverse;
        }
        return x % m;
    }
};
int main()
{
    Solution obj;
    int x, y;
    vector<int> a = {2, 3, 2}, b = {3, 5, 7};
    cout << obj.ChineseRemainder(a, b);
}