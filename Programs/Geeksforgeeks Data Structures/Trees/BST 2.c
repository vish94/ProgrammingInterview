#include<stdio.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* newnode(int data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->right = temp->left = NULL;
    return temp;
};

void printinorder(struct node* root) {
    if(root==NULL) return;
    printinorder(root->left);
    printf("%d ", root->data);
    printinorder(root->right);
}

struct node* insert(struct node* root, int data) {
    if(root==NULL) return newnode(data);
    if(root->data>data) root->left = insert(root->left, data);
    else if(data>root->data) root->right = insert(root->right, data);
    return root;
}

int find_min(struct node* node) {
    if(node->left==NULL) return node->data;
    find_min(node->left);
}

int find_max(struct node* node) {
    if(node->right == NULL) return node->data;
    find_max(node->right);

}

struct node* search(struct node* root, int key) {
    if((root==NULL)||(root->data==key)) return root;
    if(root->data<key) return search(root->right, key);
    return search(root->left, key);
};

struct node* deleteNode(struct node* root, int key) {
    // base case
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = find_min(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printinorder(root);
    root = deleteNode(root, 50);
    printinorder(root);
    printf("\nThe minimum node in the BST is %d\n", find_min(root));
    printf("\nThe maximum node in the BST is %d\n", find_max(root));
}
