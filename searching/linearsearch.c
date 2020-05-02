#include<stdio.h>

int linearsearch(int a[], int n, int target)
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] == target) return i;
	}
	return -1;
}

int main()
{
	int n;
	printf("Enter the number of elements: ");				
	scanf("%d", &n);
	int a[n];
	printf("Enter the elements: \n");
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	printf("Enter the number to search: ");
	int target;
	scanf("%d", &target);
	printf("found at index: %d\n", linearsearch(a, n, target));
}