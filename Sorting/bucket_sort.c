#include<stdio.h>
#include<stdlib.h>

struct node{
	long long int data;
	struct node *next;
};

void selection_sort(struct node **head)
{
	struct node *temp1, *temp2, *temp3;
	long long int min;
	temp1 = *head;
	temp2 = *head;
	temp3 = *head;
	min = temp1 -> data;
	while(temp1 != NULL)
	{
		while(temp2 != NULL)
		{
			if(temp2 -> data < min)
			{
				min = temp2 -> data;
				temp3 = temp2;
				temp2 = temp2 -> next;
			}
			else
				temp2 = temp2 -> next;
		}
		if(min != temp1 -> data)
		{
			temp3 -> data = temp1 -> data;
			temp1 -> data = min;
		}
		temp1 = temp1 -> next;
		if(temp1 != NULL)
			min = temp1 -> data;
		temp2 = temp1;
	}
}

void insert_node(struct node **head, long long int value, int n)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	struct node *temp1;
	temp -> data = value;
	temp -> next = NULL;
	if(n == 1)
	{
		temp -> next = *head;
		*head = temp;
	}

	else
	{
		temp1 = *head;
		for(int i = 1; i < n-1; i++)
			temp1 = temp1 -> next;

		temp -> next = temp1 -> next;
		temp1 -> next = temp;
	}
}

void bucket_sort(long long int A[], int n)
{
	struct node *arr[100000], *temp1;
	int i, temp, count = 0;
	for(i = 0; i < 100000; i++)
		arr[i] = NULL;

	for(i = 0; i < n; i++)
	{
		temp = A[i] / 100000;
		insert_node(&arr[temp], A[i], 1);
	}

	for(i = 0; i < 100000; i++)
	{
		if(arr[i] != NULL)
		{
			selection_sort(&arr[i]);
			temp1 = arr[i];
		}
	}

	for(i = 0; i < 100000; i++)
	{
		if(arr[i] != NULL)
		{
			temp1 = arr[i];
			while(temp1 != NULL)
			{
				A[count] = temp1 -> data;
				temp1 = temp1 -> next;
				count++;
			}
		}
	}
}

int main()
{
	// struct node *head, *temp;
	// head = NULL;
	// int i;
	// for(i = 0; i < 2; i++)
	// 	insert_node(&head, i + 1, 1);
	// temp = head;
	// while(temp != NULL)
	// {
	// 	printf("%d ", temp -> data);
	// 	temp = temp -> next;
	// }
	// printf("\n");
	// selection_sort(&head);
	// temp = head;
	// while(temp != NULL)
	// {
	// 	printf("%d ", temp -> data);
	// 	temp = temp -> next;
	// }
	int n, i;
	scanf("%d", &n);
	long long int A[n];
	for(i = 0; i < n; i++)
		scanf("%lld", &A[i]);
	bucket_sort(A, n);
	for(i = 0; i < n; i++)
		printf("%lld ", A[i]);

	return 0;
}
