#include<stdio.h>
int main() {
    int i, NOP, sum=0, count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10];
    float avg_wt, avg_tat;

    printf("Total number of processes in the system: ");
    scanf("%d", &NOP);
    y = NOP;

    for(i = 0; i < NOP; i++) {
        printf("\nEnter the Arrival and Burst time of Process[%d]\n", i+1);
        printf("Arrival time: ");
        scanf("%d", &at[i]);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }

    printf("Enter the Time Quantum for the process: ");
    scanf("%d", &quant);

    printf("\nProcess No \t Burst Time \t TAT \t Waiting Time\n");

    for(sum = 0, i = 0; y != 0) {
        if(temp[i] <= quant && temp[i] > 0) {
            sum += temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if(temp[i] > 0) {
            temp[i] -= quant;
            sum += quant;
        }

        if(temp[i] == 0 && count == 1) {
            y--;
            printf("Process No[%d] \t %d\t\t %d\t\t %d\n", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);
            wt += sum - at[i] - bt[i];
            tat += sum - at[i];
            count = 0;
        }

        if(i == NOP-1) {
            i = 0;
        }
        else if(at[i+1] <= sum) {
            i++;
        }
        else {
            i = 0;
        }
    }

    avg_wt = wt * 1.0 / NOP;
    avg_tat = tat * 1.0 / NOP;
    printf("\nAverage Turn Around Time: %f\n", avg_wt);
    printf("Average Waiting Time: %f\n", avg_tat);

    return 0;
}

