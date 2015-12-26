#include<stdio.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newnode(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
};

void printinorder(struct node* node) {
    if(node==NULL) return;
    printinorder(node->left);
    printf("%d ", node->data);
    printinorder(node->right);
}

int sumproperty(struct node* node) {
    int left_data = 0, right_data = 0;
    if((node==NULL) || (node->left==NULL && node->right==NULL)) return 1;
    else {
        if(node->left!=NULL) left_data = node->left->data;
        if(node->right!=NULL) right_data = node->right->data;

        if((node->data == left_data + right_data) && sumproperty(node->left) && sumproperty(node->right)) return 1;
        else return 0;
    }
}

int main() {
    struct node* root = newnode(10);
    root->left = newnode(8);
    root->left->left = newnode(3);
    root->left->right = newnode(5);
    root->right = newnode(2);
    root->right->left = newnode(2);
    printinorder(root);
    if(sumproperty(root))
    printf("\nThe given tree satisfies the children sum property ");
  else
    printf("\nThe given tree does not satisfy the children sum property ");
    return 0;
}
