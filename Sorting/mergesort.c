#include<stdio.h>

void mergesort(int a[], int l, int r);
void merge(int a[], int l, int mid, int r);

int main()
{
	int a[10];
	for(int i = 0; i < 10; i++) scanf("%d", &a[i]);
	mergesort(a, 0, 9);
	for(int i = 0; i < 10; i++) printf("%d ", a[i]);
}

void mergesort(int a[], int l, int r)
{
	int mid = (l + r) / 2;
	if(l < r)
	{
		mergesort(a, l, mid);
		mergesort(a, mid + 1, r);
		merge(a, l, mid, r);
	}
}

void merge(int a[], int l, int mid, int r)
{
	int i = l, j = mid + 1, p = 0, b[10];
	while(i <= mid && j <= r)
	{
		if(a[i] <= a[j]) b[p++] = a[i++];
		else b[p++] = a[j++];
	}
	while(i <= mid) b[p++] = a[i++];
	while(j <= r) b[p++] = a[j++];
	p = 0;
	i = l;
	while(i <= r) a[i++] = b[p++];
}