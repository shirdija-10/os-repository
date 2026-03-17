#include <stdio.h>

#define MAX 50

typedef struct {
    int pid, at, bt, rt, ct, tat, wt, qno;
} Process;

int main() {
    printf("shirdija");
    Process p[MAX];
    int n, i, time = 0, completed = 0;
    int tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Time Quantum for Queue 1 (RR): ");
    scanf("%d", &tq);

    for (i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);

        printf("PID: ");
        scanf("%d", &p[i].pid);

        printf("Arrival Time: ");
        scanf("%d", &p[i].at);

        printf("Burst Time: ");
        scanf("%d", &p[i].bt);

        printf("Queue Number (1=RR, 2=FCFS): ");
        scanf("%d", &p[i].qno);

        p[i].rt = p[i].bt;
    }

    while (completed < n) {

        int executed = 0;

        // -------- Queue 1 (Round Robin) --------
        for (i = 0; i < n; i++) {
            if (p[i].qno == 1 && p[i].at <= time && p[i].rt > 0) {

                executed = 1;

                int run = (p[i].rt > tq) ? tq : p[i].rt;

                time += run;
                p[i].rt -= run;

                if (p[i].rt == 0) {
                    p[i].ct = time;
                    completed++;
                }
            }
        }

        // -------- Queue 2 (Preemptible FCFS) --------
        if (!executed) {
            for (i = 0; i < n; i++) {
                if (p[i].qno == 2 && p[i].at <= time && p[i].rt > 0) {

                    executed = 1;

                    // Execute 1 unit only → allows preemption
                    time++;
                    p[i].rt--;

                    if (p[i].rt == 0) {
                        p[i].ct = time;
                        completed++;
                    }

                    break;
                }
            }
        }

        // CPU Idle
        if (!executed) {
            time++;
        }
    }

    // -------- Calculate TAT & WT --------
    float total_tat = 0, total_wt = 0;

    printf("\nPID\tAT\tBT\tQ\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        total_tat += p[i].tat;
        total_wt += p[i].wt;

        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].qno,
               p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Turnaround Time = %.2f", total_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);

    return 0;
}
