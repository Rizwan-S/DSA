#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	long long int key;
	struct node* next;
}node;

node* newNode(long long int key)
{
	node* new = (node*)malloc(sizeof(node));
	new->key = key;
	new->next = NULL;
	return new;
}

node* build(node* head, long long int a[], int n)
{
	head = newNode(a[0]);
	node *p = head;
	for(int i = 1; i < n; i++)
	{
		p->next = newNode(a[i]);
		p = p->next;
	}
	return head;
}

void display(node* head)
{
	while(head)
	{
		printf("%lld ", head->key);
		head = head->next;
	}
}

int main()
{
	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	long long int a[n];
	for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
	node* head = NULL;
	head = build(head, a, n);
	display(head);
	printf("\n");
}