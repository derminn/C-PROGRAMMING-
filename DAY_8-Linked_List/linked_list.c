//create Node - Allocate one node 
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

Node *createNode(int value) {
    Node *n = malloc(sizeof(Node));  /* heap allocation */
    if (n == NULL) {               /* ALWAYS check */
        fprintf(stderr, "malloc failed\n");
        exit(1);
  }
    n->data = value;               /* fill payload  */
    n->next = NULL;                /* tail safety   */
    return n;                      /* return address */
}

//APPEND- Insert at tail O(n) :
void append(Node **head, int value) {
    Node *newNode = createNode(value);

    if (*head == NULL) {           /* empty list edge case */
        *head = newNode;
        return;
    }

    Node *curr = *head;            /* walk-pointer, never touch head */
    while (curr->next != NULL)
        curr = curr->next;

    curr->next = newNode;          /* link at the end */
}

//Prepend - insert at head O(1) :
void prepend(Node **head, int value) {
    Node *newNode  = createNode(value);
    newNode->next  = *head;        /* point to old head */
    *head          = newNode;       /* new node IS head now */
}

//printList  —  traverse and print  O(n)
void printList(Node *head) {
    Node *curr = head;             /* copy of head — never walk head directly */
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;         /* advance the pointer */
    }
    printf("NULL\n");
}

//search  —  find by value  O(n)
int search(Node *head, int target) {
    Node *curr = head;             /* read-only: *head not needed */
    while (curr != NULL) {
        if (curr->data == target)  /* early exit on match */
            return 1;
        curr = curr->next;
    }
    return 0;                      /* not found */
}
deleteNode  —  remove by value  O(n)
void deleteNode(Node **head, int target) {
    if (*head == NULL) return;

//Special case: deleting the head node 
    if ((*head)->data == target) {
        Node *temp = *head;
        *head = (*head)->next;     /* skip old head */
        free(temp);                /* release memory  */
        return;
    }

    /* General case: find node before target */
    Node *curr = *head;
    while (curr->next != NULL && curr->next->data != target)
        curr = curr->next;

    if (curr->next == NULL) return; /* not found */

    Node *toDelete  = curr->next;
    curr->next      = toDelete->next; /* bypass the node */
    free(toDelete);                   /* release memory  */
}
//reverse  —  classic three-pointer technique  O(n)

void reverse(Node **head) {
    Node *prev = NULL;             /* will become new tail */
    Node *curr = *head;
    Node *next = NULL;

    while (curr != NULL) {
        next        = curr->next;  /* 1. save next      */
        curr->next  = prev;        /* 2. reverse arrow  */
        prev        = curr;        /* 3. slide prev     */
        curr        = next;        /* 4. slide curr     */
    }
    *head = prev;                  /* prev is now head  */
}





