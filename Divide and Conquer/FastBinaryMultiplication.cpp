// use karatsuba algorithm to calculate the multiplication of 2 binary numbers.
/*
suppose x and y are two binary strings. If they are not equal them make them of equal size n.
write x=xo*2^(floor(n/2)) + x1
y=yo*2^(floor(n/2)) + y1
    calcuate xoyo, (xo+yo)(x1+y1), x1y1
    and then find xoyo*2^n+{(xo+yo)(x1+y1)-xoyo-x1y1}^n/2+x1y1
*/
#include <bits/stdc++.h>
using namespace std;
void makeEqual(string &b1, string &b2)
{
    int maxLen = max(b1.size(), b2.size());
    if (maxLen > b1.size())
    {
        int k = maxLen - b1.size();
        while (k--)
        {
            b1 = "0" + b1;
        }
    }
    if (maxLen > b2.size())
    {
        int k = maxLen - b2.size();
        while (k--)
        {
            b2 = "0" + b2;
        }
    }
}
string subtractString(string &b1, string &b2)
{
    if (b1.size() != b2.size())
        makeEqual(b1, b2);
    string result;
    int n = b1.size();
    int borrow = 0, diff;
    for (int i = n - 1; i >= 0; i--)
    {
        diff = (b1[i] - '0') - (b2[i] - '0') - borrow;
        borrow = 0;
        if (diff < 0)
        {
            diff += 2;
            borrow = 1;
        }
        result += to_string(diff);
    }
    reverse(result.begin(), result.end());
    return result;
}
string addString(string &b1, string &b2)
{
    string result;
    int sum, carry = 0;
    if (b1.size() != b2.size())
    {
        makeEqual(b1, b2);
    }
    int n = b1.size();
    for (int i = n - 1; i >= 0; i--)
    {
        sum = (b1[i] - '0' + b2[i] - '0' + carry) % 2;
        carry = (b1[i] - '0' + b2[i] - '0' + carry) / 2;
        result += to_string(sum);
    }
    if (carry)
        result += '1';
    reverse(result.begin(), result.end());
    return result;
}
string fastMultiplication(string &b1, string &b2)
{
    if (b1.size() != b2.size())
        makeEqual(b1, b2);
    int n = b1.size();
    if (n == 0)
        return "0";
    if (n == 1)
    {
        return to_string((int)(b1[0] - '0') * (int)(b2[0] - '0'));
    }
    int halfLen = n / 2;
    string xo = b1.substr(0, halfLen);
    string x1 = b1.substr(halfLen);
    string yo = b2.substr(0, halfLen);
    string y1 = b2.substr(halfLen);
    string zo = fastMultiplication(xo, yo);
    string z1 = fastMultiplication(x1, y1);
    string sum0 = addString(xo, x1);
    string sum1 = addString(yo, y1);
    string z = fastMultiplication(sum0, sum1);
    // cout << z << '\n';
    z = subtractString(z, zo);
    z = subtractString(z, z1);
    for (int i = 0; i < halfLen * 2; i++)
    {
        zo += '0';
    }
    for (int i = 0; i < halfLen; i++)
    {
        z += '0';
    }
    string result = addString(zo, z);
    result = addString(result, z1);
    return result;
}
int main()
{
    string b1, b2;
    cin >> b1 >> b2;
    cout << fastMultiplication(b1, b2);
}