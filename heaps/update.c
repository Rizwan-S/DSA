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

void topdownheapify(int i, int n, int heap[])
{
	int l;
	while(2*i + 2 < n)
	{
		l = (heap[2*i + 1] < heap[2*i + 2]) ? (2*i + 1) : (2*i + 2);
		if(heap[i] > heap[l])
		{
			swap(&heap[i], &heap[l]);
			i = l;
		}
		else break;
		if(2* i + 1 < n && heap[i] > heap[2*i + 1])
		{
			swap(&heap[i], &heap[2*i + 1]);
		}
	}
}

void add(int x, int heap[], int i)
{
	heap[i] = x;
	bottomupheapify(i, heap);
}

void update(int i, int x, int n, int heap[])
{
	if(heap[i] < x)
	{
		heap[i] = x;
		topdownheapify(i, n, heap);
	}
	else if(heap[i] > x)
	{
		heap[i] = x;
		bottomupheapify(i, heap);
	}
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
	printf("\n");
	update(5, 21, n, heap);
	for(int i = 0; i < n; i++) printf("%d ", heap[i]);
	printf("\n");
	return 0;
}