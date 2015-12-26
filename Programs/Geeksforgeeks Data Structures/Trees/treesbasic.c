#include<stdio.h>

struct node {
    int data;
    struct node* right;
    struct node* left;
};

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
};

void printinorder(struct node* node) {
    if(node==NULL) return;
    printinorder(node->left);
    printf("%d ", node->data);
    printinorder(node->right);
}

void printpreorder(struct node* node) {
    if(node==NULL) return;
    printf("%d ", node->data);
    printpreorder(node->left);
    printpreorder(node->right);
}

void printpostorder(struct node* node) {
    if(node==NULL) return;
    printpostorder(node->left);
    printpostorder(node->right);
    printf("%d ", node->data);
}

int size(struct node* node) {
    if(node==NULL) return 0;
    else return(size(node->left)+1+size(node->right));
}

int maxdepth(struct node* node) {
    if(node==NULL) return 0;
    else {
        int ldepth = maxdepth(node->left);
        int rdepth = maxdepth(node->right);
        if(ldepth>rdepth) return (ldepth+1);
        else return (rdepth+1);
    }
}

int count_leaves(struct node* node) {
    if(node==NULL) return 0;
    if((node->left==NULL) && (node->right==NULL)) return 1;
    return (count_leaves(node->left)+ count_leaves(node->right));
}

int main() {
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    printf("\nPreorder traversal of binary tree is \n");
    printpreorder(root);
    printf("\nInorder traversal of binary tree is \n");
    printf("\nMax Depth of tree is %d \n", maxdepth(root));
    printinorder(root);
    printf("\nPostorder traversal of binary tree is \n");
    printpostorder(root);
    printf("\nSize of the tree is %d \n", size(root));
    printf("\nMax Depth of tree is %d \n", maxdepth(root));
    printf("\nNo. of Leaves is %d\n", count_leaves(root));
    return 0;
}
