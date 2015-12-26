#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left, *right;
};

struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
};

struct node* insert(struct node* node, int data) {
    if(node==NULL) return newNode(data);
    if(data<node->data) node->left = insert(node->left, data);
    else node->right = insert(node->right, data);
    return node;
};

void printinorder(struct node* root) {
    if(root==NULL) return;
    printinorder(root->left);
    printf("%d ", root->data);
    printinorder(root->right);
}
int main() {
    int N, i=0, num, flag=0;
    struct node* root = NULL;
    scanf("%d", &N);
    for(i=0; i<N; i++) {
        scanf("%d", &num);
        if(flag==0) {
            root = insert(root, num);
            flag=1;
        } else {
            insert(root, num);
        }
    }
    printf("Entered numbers in ascending order:");
    printinorder(root);
    return 0;
}
