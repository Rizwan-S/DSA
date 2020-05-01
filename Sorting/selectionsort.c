#include<stdio.h>

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
int main(){
	int a[10], j, max, maxindex;
	for(int i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
	for(int i = 10; i > 0; i--)
	{
		max = a[0];
		maxindex = 0;
		for(j = 0; j < i; j++)
		{
			if(a[j] > max)
			{
				max = a[j];
				maxindex = j;
			}
		}
		swap(&a[i - 1], &a[maxindex]);
	}
	for(int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
}