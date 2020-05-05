#include<stdio.h>
#include<stdbool.h>

bool find(int a[], int n, int x)
{
	int l = 0, r = n - 1;
	while(l <= r)
	{
		if(a[l] + a[r] == x) return true;
		else if(a[l] + a[r] < x) l++;
		else r--;
	}
	return false;
}

int main()
{
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	int x;
	scanf("%d", &x);
	if(find(a, n, x)) printf("True\n");
	else printf("False\n");
}
