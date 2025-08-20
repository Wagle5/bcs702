#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
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
}

int main() {
    int n = 10000;  // size of array (you can increase for bigger test)
    int arr[n];

    // Seed random numbers
    srand(time(NULL));

    // Fill array with random values
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock();  // Start timing

    bubbleSort(arr, n);

    end = clock();    // End timing

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print first 10 sorted values for verification
    printf("First 10 sorted elements: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nExecution time: %f seconds\n", cpu_time_used);

    return 0;
}
