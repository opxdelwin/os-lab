#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort_at_bt(int p[], int at[], int bt[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (at[i] > at[j] || (at[i] == at[j] && bt[i] > bt[j])) {
                swap(&p[i], &p[j]);
                swap(&at[i], &at[j]);
                swap(&bt[i], &bt[j]);
            }
        }
    }
}

void schedule(int p[], int at[], int bt[], int ct[], int tat[], int wt[], int n) {
    int time = 0, remaining_processes = n;
    int smallest_bt_index = -1, prev_index = -1;
    int *rt = (int*)malloc(n * sizeof(int)); // Remaining time for each process

    for (int i = 0; i < n; i++) {
        rt[i] = bt[i];
    }

    while (remaining_processes > 0) {
        smallest_bt_index = -1;
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                if (smallest_bt_index == -1 || rt[i] < rt[smallest_bt_index]) {
                    smallest_bt_index = i;
                }
            }
        }

        if (smallest_bt_index == -1) {
            time++;
            continue;
        }

        rt[smallest_bt_index]--;
        time++;

        if (rt[smallest_bt_index] == 0) {
            remaining_processes--;
            ct[smallest_bt_index] = time;
            tat[smallest_bt_index] = ct[smallest_bt_index] - at[smallest_bt_index];
	    wt[smallest_bt_index] = tat[smallest_bt_index] - bt[smallest_bt_index];
        }

        prev_index = smallest_bt_index;
    }

    free(rt);
}

int main() {
    int *p, *at, *bt, *tat, *wt, *ct, n;
    float awt = 0, atat = 0;

    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    p = (int*)malloc(n * sizeof(int));
    at = (int*)malloc(n * sizeof(int));
    bt = (int*)malloc(n * sizeof(int));
    ct = (int*)malloc(n * sizeof(int));
    wt = (int*)malloc(n * sizeof(int));
    tat = (int*)malloc(n * sizeof(int));

    printf("\nEnter the process IDs: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("\nEnter the arrival times: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    printf("\nEnter the burst times: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    sort_at_bt(p, at, bt, n);
    schedule(p, at, bt, ct, tat, wt, n);

    printf("\nProcess ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
        atat += tat[i];
        awt += wt[i];
    }

    atat = atat / n;
    awt = awt / n;
    printf("\nAverage Turnaround Time: %.2f", atat);
    printf("\nAverage Waiting Time: %.2f", awt);

    free(p);
    free(at);
    free(bt);
    free(ct);
    free(tat);
    free(wt);

    return 0;
}

