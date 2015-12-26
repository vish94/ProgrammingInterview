#include<stdio.h>
#define bool int

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newnode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
}

int roottoleafsum(struct node* node, int sum) {
    if(node==NULL) {
        return (sum==0);
    } else {
       bool ans = 0;
       int subsum = sum-node->data;
       if(subsum==0 && node->left == NULL && node->right==NULL) return 1;
       if(node->left)
            ans = ans || roottoleafsum(node->left, subsum);
       if(node->right)
            ans = ans || roottoleafsum(node->right, subsum);

       return ans;
    }
}

int main() {
    int sum = 12;
    struct node *root = newnode(10);
    root->left = newnode(8);
    root->right = newnode(2);
    root->left->left = newnode(3);
    root->left->right = newnode(5);
    root->right->left = newnode(2);

    if(roottoleafsum) printf("Yes");
    else printf("no");
    return 0;
}
