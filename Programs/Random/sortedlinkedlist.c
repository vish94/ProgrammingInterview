#include<stdio.h>

struct node {
    int data;
    struct node* next;
};

struct node* newnode(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
};

void push(struct node** head_ref, int data) {
    struct node* new_node = newnode(data);
    if(*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    struct node *temp = *head_ref;
    while(temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return;
}

void sortedinsert(struct node **head_ref, int data) {
    struct node* new_node = newnode(data);
    struct node *temp, *prev;
    struct node *head = *head_ref;
    /*if(*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    if(data < head->data) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }*/
    temp = head;

    while(data > temp->data) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = new_node;
    new_node->next = temp;
    return;

}


void printlist(struct node* head) {
    while(head!=NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node* root = NULL;
    push(&root, 2);
    push(&root, 5);
    push(&root, 7);
    push(&root, 8);
    push(&root, 10);
    printlist(root);
    sortedinsert(&root, 6);
    printlist(root);
    return 0;
}
