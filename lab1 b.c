#include <stdio.h>

int main() {
    int n;
    printf("shirdija");
    printf("Enter number of processes: ");
    scanf("%d", &n);


    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n], finished[n];

    for(int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        finished[i] = 0;
    }

    int current_time = 0, completed = 0;

    while(completed < n) {
        int idx = -1;
        int min_bt = 100000;


        for(int i = 0; i < n; i++) {
            if(at[i] <= current_time && finished[i] == 0) {
                if(bt[i] < min_bt) {
                    min_bt = bt[i];
                    idx = i;
                }
            }
        }

        if(idx == -1) {
            current_time++;
        } else {
            ct[idx] = current_time + bt[idx];
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            current_time = ct[idx];
            finished[idx] = 1;
            completed++;
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
