#include<stdio.h>
#include<string.h>

void swap(char *a, char *b) {
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(char arr[], int l, int r){
    if(l<r){
        swap(&arr[l], &arr[r]);
        reverse(arr, l+1, r-1);
    }
    return;
}

int main() {
    char arr[] = "Ia am a boy";
    int N = strlen(arr);
    int i,j;
    printf("Original: %s\n", arr);
    reverse(arr, 0, N-1);
    printf("Reversed: %s\n", arr);
    for(i=0; i<N; i++) {
        for(j=i; i<N; j++) {
            if(arr[j]==' ' || j==N-1) break;
        }
        reverse(arr, i, j-1);
        i = j;
    }
    printf("Final Output: %s\n", arr);

}
