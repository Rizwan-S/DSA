
#include<stdio.h>

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int a[10];
	for(int i = 0; i < 10; i++)	scanf("%d", &a[i]);
	for(int i = 10; i > 0; i--)
	{
		for(int j = 0; j < i - 1; j++)
		{
			if(a[j] > a[j + 1])	swap(&a[j], &a[j + 1]);
		}
	}
	for(int i = 0; i < 10; i++) printf("%d ", a[i]);
}
