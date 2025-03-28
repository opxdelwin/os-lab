//2. Write a program to create two threads where one thread adds half of the elements from the beginning of the array and another thread adds the remaining half of the elements from the end of the array. And at the end, the main process shows the sum of all the elements in the given array.
#include <pthread.h>
#include <stdio.h>

#define MAX_SIZE 100

int arr[MAX_SIZE];
int n;
int sum = 0;

void* addFirstHalf(void* arg) {
    int i;
    int half = n / 2;
    for (i = 0; i < half; i++) {
        sum += arr[i];
    }
    return NULL;
}

void* addSecondHalf(void* arg) {
    int i;
    int half = n / 2;
    for (i = half; i < n; i++) {
        sum += arr[i];
    }
    return NULL;
}

int main() {
    pthread_t t_id1, t_id2;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    pthread_create(&t_id1, NULL, addFirstHalf, NULL);
    pthread_create(&t_id2, NULL, addSecondHalf, NULL);

    pthread_join(t_id1, NULL);
    pthread_join(t_id2, NULL);

    printf("Sum of all elements in the array: %d\n", sum);

    return 0;
}

