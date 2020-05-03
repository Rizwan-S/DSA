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

node* delete(node* head, long long int x)
{
	if(head->key == x)
	{
		node* temp = head;
		head = head->next;
		free(temp);
	}
	else
	{
		node* p = head;
		while(p->next)
		{
			if(p->next->key == x) 
			{
				if(p->next->next)
				{
					node* temp = p->next;
					p->next = p->next->next;
					free(temp);
					break;
				}
				else
				{
					node* temp = p->next;
					p->next = NULL;
					free(temp);
					break;
				}
			}
			p = p->next;
		}
	}
	return head;
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
	printf("\nEnter a number to delete: ");
	long long int todelete;
	scanf("%lld", &todelete);
	head = delete(head, todelete);
	display(head);
	printf("\n");
}