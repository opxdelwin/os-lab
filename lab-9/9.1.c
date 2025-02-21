// FCFS PREEMPTIVE SCHEDULING ALGORITHM

// EXAMPLE OUTPUT
//
// Enter 5 processes AT: 2 5 1 0 4
// Enter 5 processes BT: 6 2 8 3 4

// Process AT      BT      CT      TAT     WT
// 0       0       3       3       3       0
// 1       1       8       11      10      2
// 2       2       6       17      15      9
// 3       4       4       21      17      13
// 4       5       2       23      18      16
// Average TAT: 12.600000
// Average WT: 8.000000

#include<stdio.h>

int main() {
    int at[5], bt[5];

    printf("Enter 5 processes AT: ");
    for(int i = 0; i < 5; i++) {
        scanf("%d", &at[i]);
    }

    printf("Enter 5 processes BT: ");
    for(int i = 0; i < 5; i++) {
        scanf("%d", &bt[i]);
    }

    for (int i = 0; i < 5; i++) {
        for (int j = i; j < 5; j++) {
            if (at[i] > at[j]) {
                int temp = at[j];
                at[j] = at[i];
                at[i] = temp;
                temp = bt[j];
                bt[j] = bt[i];
                bt[i] = temp;
            }
        }
    }

    int ct[5], wt[5], tat[5];
    int atat = 0, awt = 0;
    for(int i = 0; i < 5; i++) {
        int temp = 0;
        if (i == 0) {
            ct[i] = at[i] + bt[i];
        } else {
            if(ct[i-1] < at[i]) {
                temp = at[i] - ct[i - 1];
            }
            ct[i] = ct[i - 1] + bt[i] + temp;
        }
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        atat += tat[i];
        awt += wt[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < 5; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("Average TAT: %f\n", (double)atat / 5);
    printf("Average WT: %f\n", (double)awt / 5);
    return 0;
}