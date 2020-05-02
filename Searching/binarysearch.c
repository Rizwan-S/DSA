#include<stdio.h>

void bin(int a[], int l, int r, int search);

int main(){
	int a[10], i, search;
	for(i = 0; i < 10; i++){
		printf("Enter the %d number: ", i);
		scanf("%d", &a[i]);
	}
	printf("Enter the number to search: ");
	scanf("%d", &search);
	bin(a, 0, 9, search);
}

void bin(int a[], int l, int r, int search)
{
	if(r >= l)
	{
		int mid = (l + r) / 2;
		if(search == a[mid])
		{
			printf("The number is in the array");
		}
		else
		{
			if(a[mid] < search)
			{
				bin(a, mid + 1, r, search);
			}
			else if(a[mid] > search)
			{
				bin(a, l, mid - 1, search);
			}
		}
	}
	else
	{
		printf("The given number is not found");
	}
}