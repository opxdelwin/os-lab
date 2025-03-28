#include<stdio.h>
#define MAX 5

typedef struct RR {
    int pid;
    int at;
    int bt;
    int ct;
} Process;

Process arr[MAX] = {
    {1, 0, 3, 0},
    {2, 2, 6, 0},
    {3, 4, 4, 0},
    {4, 6, 5, 0},
    {5, 8, 2, 0}
};

int tq = 2;

void sort(Process arr[], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j].at > arr[j + 1].at) {
                Process temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int allCompleted = 0;
    int time = 0;
    int i=0;
    // sort(arr, MAX);

    while(allCompleted != 1) {
        int allDone = 0;
        for(int i = 0; i < MAX; i++) {
            if(arr[i].bt > 0) {
                allDone = 1;
                break;
            }
        }

        if(allDone == 0) {
            allCompleted = 1;
            continue;
        }

        if (arr[i].at > time) {
            time++;
            continue;
        }

        if(arr[i].bt == 0) {
            i = (i+1)%MAX;
            continue;
        }

        if(arr[i].bt > tq) {
            time += tq;
            arr[i].bt -= tq;
        } else {
            time += arr[i].bt;
            arr[i].bt = 0;
            arr[i].ct = time;
        }
        i = (i+1)%MAX;
    }

    for(int i=0; i < MAX; i++) {
        printf("Process %d: AT: %d, BT: %d, CT: %d\n", arr[i].pid, arr[i].at, arr[i].bt, arr[i].ct);
    }
    return 0;
 }