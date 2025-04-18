#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  
    int i = (low - 1);     
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {  
            i++;
            swap(&arr[i], &arr[j]); 
        }
    }
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  
        quicksort(arr, low, pi - 1);  
        quicksort(arr, pi + 1, high);  
    }
}

void printarray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);  
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n]; 

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    clock_t start, end;
    double time_taken;

    start = clock();
    quicksort(arr, 0, n - 1);
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;  
    printf("Sorted array:\n");
    printarray(arr, n);
    printf("Time taken: %f seconds\n", time_taken);
    return 0;
}
