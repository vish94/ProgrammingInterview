#include<stdio.h>

int checkschedule(int arr[], int n){
    int i;
    for(i=0; i<n; i++) {
        if(arr[i]!=0)
            return 0;
    }
    return 1;
}

int main() {
    int pi[10], timer=0, wait, totwait=0, n, i, sched[100][3], k=0, quant=3, a, flag=1;
    float avg;
    scanf("%d",&n);
    for(i=0; i<n; i++) {
        printf("Enter process %d ", i);
        scanf("%d", &pi[i]);
    }
    while(checkschedule(pi,n)==0) {
        for(i=0; i<n; i++){
            if(pi[i]==0)
                continue;
            else{
                sched[k][0] = i;
                sched[k][1] = timer;
                if(pi[i]>=quant){
                    pi[i] = pi[i]-quant;
                    timer = timer+quant;
                    sched[k][2] = timer;
                    k++;
                } else{
                    a = pi[i];
                    pi[i]=0;
                    timer = timer + a;
                    sched[k][2] = timer;
                    k++;
                }
            }
        }
    }
    for(i=0; i<k; i++){
        printf("%d %d %d\n", sched[i][0], sched[i][1], sched[i][2]);
    }

    for(i=0; i<n; i++) {
        wait=0;
        timer=i;
        for(a=0; a<k; a++){
            if(sched[a][0]==i){
                wait = wait + (sched[a][1]-timer);
                timer = sched[a][2];
            }
        }
        printf("Wait for process %d is %d\n", i, wait);
        totwait = totwait+wait;
    }
    printf("Total Wait time %d\n", totwait);
    avg = (float)totwait/n;
    printf("Average waiting time %0.1f", avg);
}
