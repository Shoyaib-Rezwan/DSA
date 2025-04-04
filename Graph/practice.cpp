#include <iostream>
using namespace std;
union Xray
{
    float f;
    int d;
    Xray(float f)
    {
        this->f = f;
    }
    void showBits();
};
void Xray::showBits()
{
    for (int i = 0; i < 32; i++)
    {
        cout << ((d >> (31 - i)) & 1);
    }
}
int main()
{
    Xray a(13.25);
    cout << a.d;
}