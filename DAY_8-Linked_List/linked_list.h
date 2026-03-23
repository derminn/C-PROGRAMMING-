#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int value);
void  append(Node **head, int value);
void  prepend(Node **head, int value);
void  printList(Node *head);
int   search(Node *head, int target);
void  deleteNode(Node **head, int target);
void  reverse(Node **head);
int   countNodes(Node *head);
void  freeList(Node *head);

#endif
