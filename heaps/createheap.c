#include<stdio.h>

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void bottomupheapify(int i, int heap[])
{
	int p = (i - 1) / 2;
	while(p >= 0 && heap[p] > heap[i])
	{
		swap(&heap[p], &heap[i]);
		i = p;
		p = (i - 1) / 2;
	}
}

void add(int x, int heap[], int i)
{
	heap[i] = x;
	bottomupheapify(i, heap);
}

int main()
{
	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	int a[n], heap[n];
	printf("Enter the elements:\n");
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < n; i++) add(a[i], heap, i);
	for(int i = 0; i < n; i++) printf("%d ", heap[i]);
}