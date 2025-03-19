#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10000

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[MAX_SIZE], R[MAX_SIZE];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// MergeSort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int N;
    int arr[MAX_SIZE];

    printf("Enter number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &N);

    if (N > MAX_SIZE) {
        printf("Error: Maximum size exceeded.\n");
        return 1;
    }

    srand(time(0));
    for (int i = 0; i < N; i++)
        arr[i] = rand() % 10000;

    clock_t start = clock();
    mergeSort(arr, 0, N - 1);
    clock_t end = clock();

    printf("Sorted elements: ");
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d elements: %f seconds\n", N, time_taken);

    return 0;
}
