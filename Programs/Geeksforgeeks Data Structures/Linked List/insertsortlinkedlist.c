#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* newnode(int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
};

void printlist(struct node* node) {
    struct node* temp = node;
    while(temp!=NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void push(struct node** head_ref, int data) {
    struct node* new_node = newnode(data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void sortedinsert(struct node**, struct node*);

void insertionsort(struct node** head_ref) {
    struct node* sorted = NULL;
    struct node* current = *head_ref;
    while(current!=NULL) {
        struct node* next = current->next;
        sortedinsert(&sorted, current);
        current = next;
    }
    *head_ref = sorted;
}

void sortedinsert(struct node** head_ref, struct node* new_node) {
    if((*head_ref) == NULL || (*head_ref)->data>new_node->data) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }
    struct node* current = *head_ref;
    while(current!=NULL && current->data<new_node->data) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return;
}

int main() {
    struct node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    printlist(head);
    insertionsort(&head);
    printlist(head);
    return 0;
}
