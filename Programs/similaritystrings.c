#include<stdio.h>
#include<string.h>

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        char string[100001];
        int i,j,count=0, curr=0,k;
        scanf("%s", &string);
        for(i=0; i<strlen(string); i++) {
            curr=0;
            k=0;
            for(j=i; j<strlen(string);j++){
                if(string[j]==string[k]){
                    k++;
                    curr++;
                }
                else break;
            }
            count = count + curr;
        }
        printf("%d\n", count);
    }
}
