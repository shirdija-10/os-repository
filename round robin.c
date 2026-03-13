#include <stdio.h>
int main()
{
    printf("shirdija");
    int n, tq;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum: ");
    scanf("%d", &tq);
    int pid[n], at[n], bt[n], rt[n];
    int wt[n], tat[n], ct[n];
    int queue[100], front = 0, rear = 0;
    int visited[n];
    for(int i = 0; i < n; i++)
    {
        printf("\nEnter Process ID: ");
        scanf("%d", &pid[i]);
        printf("Enter Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Enter Burst Time: ");
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
        visited[i] = 0;
    }
    int current_time = 0;
    int completed = 0;
    double avg_wt = 0, avg_tat = 0;
    while(completed < n)
    {
        for(int i = 0; i < n; i++)
        {
            if(at[i] <= current_time && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
        if(front == rear)
        {
            current_time++;
            continue;
        }
        int p = queue[front++];
        if(rt[p] > tq)
        {
            current_time += tq;
            rt[p] -= tq;
            for(int i = 0; i < n; i++)
            {
                if(at[i] <= current_time && visited[i] == 0)
                {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
            queue[rear++] = p;
        }
        else
        {
            current_time += rt[p];
            rt[p] = 0;
            ct[p] = current_time;
            tat[p] = ct[p] - at[p];
            wt[p] = tat[p] - bt[p];
            avg_wt += wt[p];
            avg_tat += tat[p];
            completed++;
        }
    }
    avg_wt /= n;
    avg_tat /= n;
    for(int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i],ct[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time = %.2lf", avg_wt);
    printf("\nAverage Turnaround Time = %.2lf", avg_tat);
    return 0;
}
