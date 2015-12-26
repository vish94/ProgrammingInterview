#include<stdio.h>
#include<string.h>

struct book {
    long long int data;
    char name[20];
    struct book* next;
};

int isEmpty(struct book* root) {
    return !root;
}

struct book* newnode(long long int data, char name[]) {
    struct book* new_node = (struct book*)malloc(sizeof(struct book));
    new_node->data = data;
    strcpy(new_node->name, name);
    new_node->next = NULL;
    return new_node;
};

void push(struct book** root, long long int data, char name[]) {
    struct book* new_node = newnode(data,name);
    if(*root==NULL){
        *root = new_node;
        return;
    }

    new_node->next = *root;
    *root = new_node;
    return;
}

void printstack(struct book *root) {
    struct book* temp = root;
    while(temp!=NULL) {
        printf("%lld %s\n", temp->data, temp->name);
        temp = temp->next;
    }
}

void pop(struct book** root) {
    if (isEmpty(*root))
        return -1;
    struct book* temp = *root;
    *root = (*root)->next;
    free(temp);
}

int main() {
    int T;
    long long int min_exe = 1000000;
    scanf("%d", &T);
    struct book* root = NULL;
    while(T--) {
        long long int N;
        char name[20];
        scanf("%lld", &N);
        if(N==-1) {
            long long int count=0;
            struct book* temp = root;
            while(temp!=NULL) {
                if(temp->data==min_exe){
                    printf("%lld %s\n", count, temp->name);
                    pop(&root);
                    break;
                } else{
                    count++;
                    pop(&root);
                    temp = temp->next;
                }
            }
        }
        else {
            if(N<=min_exe) min_exe = N;
            scanf("%s", &name);
            push(&root, N, name);
        }
    }
    return 0;

}
