#include <stdio.h>

#define MAX 10
#define INF 999999

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}


int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}


int find_lcm(int arr[], int n) {
    int res = arr[0];
    for (int i = 1; i < n; i++) {
        res = lcm(res, arr[i]);
    }
    return res;
}

int main() {
    int n, i;
    printf("shirdija");

    int burst[MAX], deadline[MAX], period[MAX];
    int remaining[MAX];
    int abs_deadline[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Time, Deadline, Period:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &burst[i], &deadline[i], &period[i]);
        remaining[i] = 0;
        abs_deadline[i] = INF;
    }


    int hyper = find_lcm(period, n);


    printf("\nPID\tBurst\tDeadline\tPeriod\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t\t%d\n", i + 1, burst[i], deadline[i], period[i]);
    }

    printf("Scheduling occurs for %d ms\n\n", hyper);


    for (int time = 0; time < hyper; time++) {


        for (i = 0; i < n; i++) {
            if (time % period[i] == 0) {
                remaining[i] = burst[i];
                abs_deadline[i] = time + deadline[i];
            }
        }

        int selected = -1;
        int min_deadline = INF;


        for (i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                if (abs_deadline[i] < min_deadline) {
                    min_deadline = abs_deadline[i];
                    selected = i;
                }
            }
        }


        if (selected == -1) {
            printf("%dms: CPU is idle.\n", time);
        } else {
            printf("%dms: Task %d is running.\n", time, selected + 1);

            remaining[selected]--;

            if (remaining[selected] == 0) {
                abs_deadline[selected] = INF;
            }
        }
    }

    return 0;
}
