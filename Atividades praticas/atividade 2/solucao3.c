#include <stdio.h>
#include <stdlib.h>


void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i <= n - 2; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i <= n - 1; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] >= key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}