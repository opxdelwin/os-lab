// SJF PREEMPTIVE SCHEDULING ALGORITHM

// EXAMPLE OUTPUT
//
// Enter 5 processes AT: 2 5 1 0 4
// Enter 5 processes BT: 6 2 8 3 4

// Process AT      BT      CT      TAT     WT
// 4       0       3       3       3       0
// 3       1       8       23      22      14
// 1       2       6       9       7       1
// 5       4       4       15      11      7
// 2       5       2       11      6       4
// Average TAT: 9.800000
// Average WT: 5.200000


#include <stdio.h>

int getNextIndex(int at[], int bt[], int hasRun[], int pid[], int time)
{
    int index = -1;
    for (int i = 0; i < 5; i++)
    {
        if (hasRun[i] == 1)
        {
            continue;
        }

        if (at[i] <= time)
        {
            if (index == -1)
            {
                index = i;
            }
            else
            {
                if (bt[i] == bt[index])
                {
                    if (pid[i] < pid[index])
                    {
                        index = i;
                    }
                }
                else if (bt[i] < bt[index])
                {
                    index = i;
                }
            }
        }
    }

    return index;
}

int main()
{
    int at[5], bt[5], pid[5];

    printf("Enter 5 processes AT: ");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &at[i]);
    }

    printf("Enter 5 processes BT: ");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &bt[i]);
        pid[i] = i;
    }

    int time = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = i; j < 5; j++)
        {
            if (at[i] > at[j])
            {
                int temp = at[j];
                at[j] = at[i];
                at[i] = temp;
                temp = bt[j];
                bt[j] = bt[i];
                bt[i] = temp;
                temp = pid[j];
                pid[j] = pid[i];
                pid[i] = temp;
            }
        }
    }

    int ct[5], wt[5], tat[5];
    int atat = 0, awt = 0;
    int hasRun[5] = {0, 0, 0, 0, 0};

    for (int i = 0; i < 5; i++)
    {
        int index = getNextIndex(at, bt, hasRun, pid, time);
        if (index == -1)
        {
            printf("breaking at %d\n", time);
            break;
        }

        hasRun[index] = 1;
        if (i == 0) {
            ct[index] = at[index] + bt[index];
        } else {
            if (time < at[index]) {
                time = at[index];
            }
            ct[index] = time + bt[index];
        }
        tat[index] = ct[index] - at[index];
        wt[index] = tat[index] - bt[index];
        atat += tat[index];
        awt += wt[index];
        time = ct[index];
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i] + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("Average TAT: %f\n", (double)atat / 5);
    printf("Average WT: %f\n", (double)awt / 5);

    return 0;
}