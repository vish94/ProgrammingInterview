#include<stdio.h>
#include<string.h>

int samechars(char s1[100], char s2[100]) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int char1[200], char2[200];
    int i=0;
    for(i=0; i<200; i++) {
        char1[i]=0;
        char2[i]=0;
    }
    if(len1==len2) {
        for(i=0; i<len1; i++) {
            char1[s1[i]]++;
            char2[s1[i]]++;
        }
        for(i=0; i<200; i++) {
            if(char1[i]!=char2[i])
                return 0;
        }
        return 1;
    } else{
        return 0;
    }
}

int isSame(char s1[100], char s2[100]) {
    int i=0;
    for(i=0; i<strlen(s1); i++) {
        if(s1[i]!=s2[i])
            return 0;
    }
    return 1;
}



int swap(char s1[100], char s2[100]) {
    int i=0, j=0;
    int count=0;
    char key;
    while(isSame(s1,s2)==0) {
        count++;
        for(i=strlen(s2)-1; i>=0; i--) {
            if(s2[i]!=s1[i]) {
                key = s1[i];
                for(j=i; j>0; j--) {
                    s1[j] = s1[j-1];
                }
                s1[j] = key;
                break;
            }
        }
    }
    return count;
}

int main() {
    char s1[100], s2[100];
    int len1, len2;
    int swaps;
    scanf("%s", &s1);
    len1 = strlen(s1);
    len2 = strlen(s2);
    scanf("%s", &s2);
    if(samechars(s1,s2)==1) {
        printf("Yes");
        swaps = swap(s1,s2);
        printf(" in %d swaps", swaps);
    } else {
        printf("No");
    }
}
