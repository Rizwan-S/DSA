#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _LNode {
    int key;
    int value;
    struct _LNode* next;
};

typedef struct _LNode LNode;

const int P = 299;  // Recommended to be a prime
const int M = 29;   // Recommended to be a prime
#define HASHTABLE_SIZE P

// Note - We are making hashtable size = P to make implementation easier.
// Generally, hashtable is independent of the problem

// Function to insert key, value into hashtable
void insert(LNode* hashtable[], int key, int value) {
    int index = key % HASHTABLE_SIZE;  // our hash function is simple here

    LNode* prevHead = hashtable[index];  // previous head in LL

    // Create a new node
    LNode* newNode = (LNode*)malloc(sizeof(LNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = prevHead;  // attach to previous head in LL

    // Insert it
    hashtable[index] = newNode;
}

// Function which returns Linked List for a given key in hashtable
// returns -1 if absent
LNode* get(LNode* hashtable[], int key) {
    int index = key % HASHTABLE_SIZE;
    LNode* head = hashtable[index];  // previous head in LL

    return head;
}

// Function to check if s1 and s2 are equal upto a given length
int cmp(char* s1, char* s2, int length) {
    while (length--) {
        if (*s1 != *s2) return 0;
        s1++;
        s2++;
    }
    return 1;
}

// Helper function to create and initialize hashtable
LNode** initHashtable() {
    LNode** hashtable = malloc(sizeof(LNode*) * HASHTABLE_SIZE);  // create
    memset(hashtable, 0, sizeof(LNode*) * HASHTABLE_SIZE);        // initialize
    return hashtable;
}

// Helper function to delete linkedlist
void freeLinkedList(LNode* head) {
    while (head) {
        LNode* temp = head->next;
        free(head);
        head = temp;
    }
}

// Helper function to delete hashtable
void freeHashtable(LNode** hashtable) {
    for (int i = 0; i < HASHTABLE_SIZE; i++)
        freeLinkedList(hashtable[i]);
    free(hashtable);
}

// Function checks is there a commong substring in s1 and s2 of size length
// Complexity O(size(S1) + size(S2))

// Note:
// When we insert key, we insert the rabin karp hash value as key
// The value is the index of the substring
// If there is a hash match, we need to still check if the substrings are actually equal
// This is due to hash colissions.
// x1 = x2 -> hash(x1) = hash(x2)
// hash(x1) != hash(x2) -> x1 != x2
// hash(x1) = hash(x2) doesn't imply x1 = x2

int isPossible(char s1[], char s2[], int length) {
    // Create and initialize hashtable
    LNode** hashtable = initHashtable();

    int n1 = strlen(s1);
    int n2 = strlen(s2);

    int hash = 0;
    int h = 1;
    int i;
    for (i = 0; i < length; i++) {
        if (i > 0) h *= M;
        hash = hash * M + (s1[i] - 'a' + 1);
        hash %= P;
        h %= P;
    }

    // h = M ^ (length - 1)
    insert(hashtable, hash, 0);
    for (i = length; i < n1; i++) {
        hash = (hash - h * (s1[i - length] - 'a' + 1) + P) % P;
        hash = hash * M + (s1[i] - 'a' + 1);
        hash %= P;
        insert(hashtable, hash, i - length + 1);
    }

    // Now hashtable is populated
    // String 2 starts
    hash = 0;
    for (i = 0; i < length; i++) {
        hash = hash * M + (s2[i] - 'a' + 1);
        hash %= P;
    }

    LNode* head = get(hashtable, hash);
    // we need to check if strings are equal to avoid hash collission

    while (head) {
        if (cmp(s1 + head->value, s2 + 0, length)) {
            freeHashtable(hashtable);
            return 1;
        }
        head = head->next;
    }

    for (i = length; i < n2; i++) {
        hash = (hash - h * (s2[i - length] - 'a' + 1) + P) % P;
        hash = hash * M + (s2[i] - 'a' + 1);
        hash %= P;
        LNode* head = get(hashtable, hash);
        // we need to check if strings are equal to avoid hash collission
        while (head) {
            if (cmp(s1 + head->value, s2 + i - length + 1, length)) {
                freeHashtable(hashtable);
                return 1;
            }
            head = head->next;
        }
    }

    freeHashtable(hashtable);

    return 0;
}

int min(int a, int b) { return a < b ? a : b; }

int main() {
    char s1[100];
    char s2[100];
    scanf("%s", s1);
    scanf("%s", s2);
    int ans = 0;
    int l = 1;
    int r = min(strlen(s1), strlen(s2));
    while (l <= r) {
        int m = (l + r) / 2;
        if (isPossible(s1, s2, m)) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    printf("%d\n", ans);
}