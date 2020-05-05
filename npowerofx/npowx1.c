#include<stdio.h>

int findpower(int x, int n)
{
    int y = 1;
    while(n > 0)
    {
        if(n % 2 == 1) y *= x;
        x *= x;
        n /= 2;
    }
    return y;
}

int main()
{
    int x, n;
    scanf("%d %d", &x, &n);
    printf("%d", findpower(x,n));
    return 0;
}