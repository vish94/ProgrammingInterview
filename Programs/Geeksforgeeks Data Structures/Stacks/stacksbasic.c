#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct StackNode {
    int data;
    struct StackNode* next;
};

struct StackNode* newNode(int data) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(struct StackNode* root) {
    return !root;
}
void push(struct StackNode** root, int data) {
    struct StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%d pushed to stack \n", data);
}

void pop(struct StackNode** root){
    if(isEmpty(*root)) return INT_MIN;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    printf("%d popped from stack \n", popped);
}

void traverse(struct StackNode* root) {
    struct StackNode* temp = root;
    while(temp!=NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}
int main() {
    struct StackNode* root = NULL;
    push(&root, 10);
    traverse(root);
    push(&root, 20);
    traverse(root);
    push(&root, 30);
    traverse(root);
    pop(&root);
    traverse(root);
    return 0;
}
