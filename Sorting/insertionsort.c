#include<stdio.h>

int main()
{
	int i, j, temp, a[10];
	for(i = 0; i < 10; i++)	scanf("%d", &a[i]);
	for(i = 1; i < 10; i++)
	{
		temp = a[i];
		j = i - 1;
		while(j >= 0 && a[j] > temp)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
	for(i = 0; i < 10; i++) printf("%d ", a[i]);
}