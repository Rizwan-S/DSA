#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

node* circular(node* head)
{
	node* p = head;
	while(p->next) p = p->next;
	p->next = head;
	return head;
}

bool floyd(node* head)
{
	node* p1 = head, *p2 = head;
	while(p1 && p2 && p2->next)
	{
		p1 = p1->next;
		p2 = p2->next->next;
		if(p1 == p2) return true;
	}
	return false;
}

int main()
{
	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	long long int a[n];
	for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
	node* head1 = NULL;
	head1 = build(head1, a, n);
	printf("Enter the number of elements for circular list: ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
	node* head2 = NULL;
	head2 = build(head2, a, n);
	head2 = circular(head2);
	if(floyd(head1)) printf("Head1 : true\n");
	else printf("Head1 : false\n");
	if(floyd(head2)) printf("Head2 : true\n");
	else printf("Head2 : false\n");	
}