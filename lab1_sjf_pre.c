#include <stdio.h>
#include <limits.h>

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d",&n);

    int pid[n], at[n], bt[n], rt[n];
    int ct[n], tat[n], wt[n];

    for(int i=0;i<n;i++){
        pid[i] = i+1;
    }

    for(int i=0;i<n;i++){
        printf("Enter arrival time and burst time for process %d: ",i+1);
        scanf("%d %d",&at[i],&bt[i]);
        rt[i] = bt[i];
    }

    int completed = 0;
    int t = 0;

    while(completed < n){

        int idx = -1;
        int min_rt = INT_MAX;

        for(int i=0;i<n;i++){
            if(at[i] <= t && rt[i] > 0){
                if(rt[i] < min_rt ||
                   (rt[i] == min_rt && at[i] < at[idx])){

                    min_rt = rt[i];
                    idx = i;
                }
            }
        }

        if(idx == -1){
            t++;
            continue;
        }

        rt[idx]--;
        t++;

        if(rt[idx] == 0){
            completed++;

            ct[idx] = t;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            if(wt[idx] < 0)
                wt[idx] = 0;
        }
    }

    float avg_wt = 0, avg_tat = 0;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);

        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nAverage Waiting Time: %.2f",avg_wt/n);
    printf("\nAverage Turnaround Time: %.2f\n",avg_tat/n);

    return 0;
}
