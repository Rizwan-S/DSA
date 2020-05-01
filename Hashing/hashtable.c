#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	int index;
	struct node* next;
}node;

void insert_into_table(node** hashtable, int index, int tc);
void insert_new_node(node** head, int index);
void search(node** hashtable, char text[], char pattern[], int patternlength, int pc);

int main(){
	node** table = calloc(108, sizeof(node*));
	char text[1000], pattern[1000];
	printf("Enter the string:");
	scanf("%s", text);
	printf("Enter the pattern:");
	scanf("%s", pattern);
	int textlength = strlen(text), patternlength = strlen(pattern);
	int p = 109, pc = (pattern[0] - '0'), tc = (text[0] - '0'), mul = 10, i;
	for(i = 1; i < patternlength; i++){
		pc = ((10 * pc) + (pattern[i] - '0')) % p;
		tc = ((10 * tc) + (text[i] - '0')) % p;
		mul = (mul * 10) % p;
	}
	insert_into_table(table, 0, tc);
	for(i = 1; i <= textlength - patternlength; i++){
		tc = (tc * 10 + (text[i + patternlength - 1] - '0') - mul * (text[i - 1] - '0')) % p;
		if( tc < 0) tc = tc + p;
       	insert_into_table(table, i, tc);
	}
	search(table, text, pattern, patternlength, pc);
}

void insert_into_table(node** hashtable, int index, int tc){
	if(hashtable[tc] == NULL){
		hashtable[tc] = malloc(sizeof(node*));
		node* head = NULL;
		insert_new_node(&head, index);
		hashtable[tc] = head;
	}else{
		node* head = hashtable[tc];
		insert_new_node(&head, index);
		hashtable[tc] = head;
	}
}

void insert_new_node(node** head, int index){
	node* new_node = malloc(sizeof(node*));
	new_node->index = index;
	new_node->next = NULL;
	if(*head == NULL)*head = new_node;
	else{
		node* current = *head;
		while(current->next != NULL) current = current->next;
		current->next = new_node;
	}
}

void search(node** hashtable, char text[], char pattern[], int patternlength, int pc){
	node* head = hashtable[pc];
	int i;
	while(head != NULL){
		for(i = 0; i < patternlength; i++){
			if(text[head->index + i] != pattern[i])	break;
		}
		if(i == patternlength) printf("Match found at: %d\n", head->index);
		head = head->next;
	}
}