#include<stdio.h>
#include<string.h>

void printSubStr(char *str, int low, int high) {
    int i;
    for(i=low; i<=high; i++)
        printf("%c", str[i]);
}

int longestPalSubstr(char *str) {
    int n = strlen(str);
    int table[n][n];
    int maxlength,i;
    int start=0, k;
    memset(table, 0, sizeof(table));
    maxlength = 1;
    for(i=0; i<n; i++) {
        table[i][i] = 1;
    }
    for(i=0; i<n-1; i++) {
        if(str[i]==str[i+1]) {
            table[i][i+1] = 1;
            start = i;
            maxlength = 2;
        }
    }
    for(k=3; k<=n; ++k) {
        for(i=0; i<n-k+1; i++) {
            int j = i+k-1;
            if(table[i+1][j-1]==1 && str[i]==str[j]) {
                table[i][j] = 1;
                if(k>maxlength) {
                    start = i;
                    maxlength = k;
                }
            }
        }
    }
    for(i=0; i<n; i++) {
        for(k=0; k<n; k++)
            printf("%d ", table[i][k]);
        printf("\n");
    }
    printf("Longest palindrome substring is: ");
    printSubStr(str, start, start+maxlength-1);
    return maxlength;
}

int main() {
    char str[] = "forgeeksskeegfor";
    printf("\nLength is %d\n", longestPalSubstr(str));
    return 0;
}
