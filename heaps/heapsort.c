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

void buildheap(int heap[], int n)
{
	for(int i = 1; i < n; i++) bottomupheapify(i, heap);
}

void deletemin(int heap[], int n)
{
	int x = heap[0];
	heap[0] = heap[--n];
	heap[n] = x;
	topdownheapify(0, n, heap);
}

int main()
{
	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	int heap[n], m = n;
	printf("Enter the elements:\n");
	for(int i = 0; i < n; i++) scanf("%d", &heap[i]);
	//Make-heap
	buildheap(heap, n);
	for(int i = 0; i < n; i++) printf("%d ", heap[i]);
	printf("\n");
	//Heap-sort
	for(int i = n; i > 0; i--)
	{
		buildheap(heap, i);
		deletemin(heap, i);
	}
	for(int i = n - 1; i >= 0; i--) printf("%d ", heap[i]);
	printf("\n");
	return 0;
}