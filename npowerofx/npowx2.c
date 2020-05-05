#include<stdio.h>

int findpower(int x, int n)
{
    if(n == 0) return 1;
    else if(n % 2 == 0) return findpower(x*x, n / 2);
    else return x * findpower(x*x, n / 2);
}

int main()
{
    int x, n;
    scanf("%d %d", &x, &n);
    printf("%d", findpower(x,n));
    return 0;
}