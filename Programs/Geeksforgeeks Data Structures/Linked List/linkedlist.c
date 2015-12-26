#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};

void push(struct node** head_ref, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insertafter(struct node* prev_node, int new_data) {
    if(prev_node==NULL){
        return;
    }
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void append(struct node** head_ref, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;
    if(*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    struct node* last = *head_ref;
    while(last->next!=NULL) last=last->next;
    last->next = new_node;
    return;
}

void printlist(struct node* node) {
    while(node!=NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void deletenode(struct node **head_ref, int key) {
    struct node* temp = *head_ref, *prev;

    if(temp!=NULL && temp->data==key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!=key) {
        prev = temp;
        temp=temp->next;
    }
    if(temp==NULL) return;
    prev->next = temp->next;
    free(temp);
}

int main() {
    struct node* head=NULL;
    append(&head,6);
    printlist(head);
    push(&head,7);
    printlist(head);
    push(&head,1);
    printlist(head);
    append(&head,4);
    printlist(head);
    insertafter(head->next->next, 8);
    printlist(head);
    deletenode(&head, 7);
    printlist(head);
    return 0;

}
