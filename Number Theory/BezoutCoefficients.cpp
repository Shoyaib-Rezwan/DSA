// https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
#include <iostream>
#include <vector>
using namespace std;
// int ExtendedGCD(int x, int y, int *a, int *b)
// {
//     if (y == 0)
//     {
//         *a = 1;
//         *b = 0;
//         return x;
//     }
//     int *x1, *y1, gcd;
//     gcd = ExtendedGCD(y, x % y, x1, y1);
//     *a = *y1;
//     *b = *x1 - (x / y) * *y1;
//     return gcd;
// }
// GFG Problem Submit Link::https://www.geeksforgeeks.org/problems/extended-euclidean-algorithm3848/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
class Solution
{
public:
    vector<int> gcd(int a, int b)
    {
        // code here
        vector<int> Bezout = {a, 1, 0};
        if (b == 0)
            return Bezout;

        else
        {
            vector<int> temp = gcd(b, a % b);
            Bezout.at(0) = temp.at(0);
            Bezout.at(1) = temp.at(2);
            Bezout.at(2) = temp.at(1) - (a / b) * temp.at(2);
        }
        return Bezout;
    }
};
int main()
{
    Solution obj;
    vector<int> result = obj.gcd(9702, 97);
    cout << result.at(1) << " " << result.at(2);
}