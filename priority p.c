#include <stdio.h>

int main()
{
      printf("shirdija");
    int n, i, current_time = 0, completed_count = 0;
    int pid[20], at[20], bt[20], pr[20];
    int ct[20], tat[20], wt[20],rt[20];
    int completed[20] = {0};
    float avg_tat = 0, avg_wt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nProcess %d\n", i + 1);
        printf("Enter Process ID: ");
        scanf("%d", &pid[i]);
        printf("Enter Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Enter Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Enter Priority: ");
        scanf("%d", &pr[i]);
        rt[i]=bt[i];
    }

    while(completed_count < n)
    {
        int highest_priority = 9999;
        int selected = -1;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= current_time && rt[i]> 0)
            {
                if(pr[i] < highest_priority)
                {
                    highest_priority = pr[i];
                    selected = i;
                }
            }
        }

        if(selected == -1)
        {
            current_time++;
        }
        else
        {
            rt[selected]=rt[selected]-1;
            current_time+=1;
            if(rt[selected]==0)
            {
                 ct[selected] = current_time ;
            tat[selected] = ct[selected] - at[selected];
            wt[selected] = tat[selected] - bt[selected];
              completed[selected] = 1;
             completed_count++;
            }


        }
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);

        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    avg_tat /= n;
    avg_wt /= n;

    printf("\nAverage Turnaround Time = %.2f", avg_tat);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt);

    return 0;
}
