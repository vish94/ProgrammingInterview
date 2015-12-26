#include<stdio.h>

struct node {
    int key;
    struct node *left, *right;
};

struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = data;
    temp->left = temp->right = NULL;
    return temp;
};

void inorder(struct node *root){
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

struct node* insert(struct node* node, int key) {
    if(node==NULL) return newNode(key);
    if(key<node->key) node->left = insert(node->left, key);
    else node->right = insert(node->right, key);
    return node;
}

struct node* search(struct node* root, int key) {
    if((root==NULL)||(root->key==key)) return root;
    if(root->key<key) return search(root->right, key);
    return search(root->left, key);
};
struct node* minvaluenode(struct node* node) {
    struct node* current = node;
    while(current->left!=NULL) current = current->left;
    return current;
};

struct node* deletenode(struct node* root, int key) {
    if(root==NULL) return root;

    if(key<root->key) root->left = deletenode(root->left, key);
    else if(key>root->key) root->right = deletenode(root->right, key);
    else {
        if(root->left==NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minvaluenode(root->right);
        root->key = temp->key;
        root->right = deletenode(root->right, temp->key);
    }
    return root;
};
int main() {
    struct node* root = NULL;
    root =insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inorder(root);
    deletenode(root, 20);
    inorder(root);
    deletenode(root, 30);
    inorder(root);
    deletenode(root, 50);
    inorder(root);
    return 0;
}
