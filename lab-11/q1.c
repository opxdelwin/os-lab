//1. Write a program to create an array globally and input elements in the main function. Use a thread to sort the array and display the sorted elements in the main function.
#include <pthread.h>
#include <stdio.h>

#define MAX_SIZE 100

int arr[MAX_SIZE];
int n;

void* sortArray(void* arg) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return NULL;
}

int main() {
    pthread_t t_id;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array elements before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    pthread_create(&t_id, NULL, sortArray, NULL);
    pthread_join(t_id, NULL);

    printf("Array elements after sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

