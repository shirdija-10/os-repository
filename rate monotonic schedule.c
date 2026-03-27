#include <stdio.h>
#include <math.h>

#define MAX 10

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
    printf("shirdija");
    int n, i, j;
    int C[MAX], P[MAX], remaining[MAX];

    printf("Enter the number of processes:");
    scanf("%d", &n);

    printf("Enter the CPU burst times:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &C[i]);

    printf("Enter the time periods:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &P[i]);


    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (P[i] > P[j]) {
                int temp;
                temp = P[i]; P[i] = P[j]; P[j] = temp;
                temp = C[i]; C[i] = C[j]; C[j] = temp;
            }
        }
    }

    int hyper = find_lcm(P, n);
    printf("LCM=%d\n\n", hyper);

    printf("Rate Monotone Scheduling:\n");
    printf("PID\tBurst\tPeriod\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", i + 1, C[i], P[i]);
    }


    double U = 0;
    for (i = 0; i < n; i++) {
        U += (double)C[i] / P[i];
    }

    double bound = n * (pow(2, (double)1/n) - 1);

    printf("\n%f <= %f => %s\n",
           U, bound, (U <= bound) ? "true" : "false");

    printf("Scheduling occurs for %d ms\n\n", hyper);

    // Initialize
    for (i = 0; i < n; i++)
        remaining[i] = 0;


    for (int t = 0; t < hyper; t++) {


        for (i = 0; i < n; i++) {
            if (t % P[i] == 0) {
                remaining[i] = C[i];
            }
        }

        int executed = -1;


        for (i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                executed = i;
                break;
            }
        }

        if (executed != -1) {
            printf("%dms onwards: Process %d running\n", t, executed + 1);
            remaining[executed]--;
        } else {
            printf("%dms onwards: CPU is idle\n", t);
        }
    }

    return 0;
}
