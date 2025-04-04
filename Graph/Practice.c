#include<stdio.h>
union test{
    long long a;
    double b;
};
int main()
{
    union test t1;
    t1.b = 13.25;
    for (int i = 0; i < 64; i++)
    {
        if ((t1.a >> (63 - i)) & 1)
            printf("1");
        else
            printf("0");
}

}