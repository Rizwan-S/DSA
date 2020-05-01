#include<stdio.h>
#include<stdlib.h>

void RQS(int a[], int i, int j);
void swap(int* x, int* y);
int partition(int a[], int i, int j, int pivot);

int main()
{
	int a[10];
	for(int i = 0; i < 10; i++)
	{
		printf("Enter %d number: ", i + 1);
		scanf("%d", &a[i]);
	}
	RQS(a, 0, 9);
	for(int i = 0; i < 10; i++) printf("%d ", a[i]);
}

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void RQS(int a[], int i, int j)
{
	if (i < j)
	{
		int p = (rand() % (j - i + 1)) + i;
		swap(&a[i], &a[p]);
		int k = partition(a, i + 1, j, a[i]);
		RQS(a, i, k - 1);
		RQS(a, k + 1, j);
	}
}

int partition(int a[], int i, int j, int pivot)
{
	int l = i, r = j;
	while(l <= r)
	{
		while(l <= r && a[l] <= pivot) l++;
		while(l <= r && a[r] > pivot) r--;
		if(l <= r)
		{
			swap(&a[l], &a[r]);
			l++;
			r--;
		}
	}
	int k = l - 1;
	a[i - 1] = a[k];
	a[k] = pivot;
	return k;
}