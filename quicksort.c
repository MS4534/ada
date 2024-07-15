
include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
int t = *a;
*a = *b;
*b = t;
}

int partition(int arr[], int low, int high) {
int pivot = arr[high]; // pivot
int i = (low - 1); // Index of smaller element
for (int j = low; j <= high - 1; j++) {
// If current element is smaller than or equal to pivot
if (arr[j] <= pivot) {
i++;
swap(&arr[i], &arr[j]);
}
}
swap(&arr[i + 1], &arr[high]);
return (i + 1);
}

void quickSort(int arr[], int low, int high) {
if (low < high) {

int pi = partition(arr, low, high);

quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
}
}

void printArray(int arr[], int size) {
for (int i = 0; i < size; i++)
printf("%d ", arr[i]);
printf("\n");
}

void generateRandomArray(int arr[], int size) {
for (int i = 0; i < size; i++) {
arr[i] = rand() % 10000; // Random number between 0 and 9999
}
}
int main() {
int n;
srand(time(0)); 
printf("Enter the number of elements (n > 5000): ");
scanf("%d", &n);
if (n <= 5000) {
printf("Please enter a value greater than 5000.\n");
return 1;
}
int* arr = (int*)malloc(n * sizeof(int));
if (arr == NULL) {
printf("Memory allocation failed\n");
return 1;
}
generateRandomArray(arr, n);
clock_t start, end;
double cpu_time_used;
start = clock();
quickSort(arr, 0, n - 1);
end = clock();
cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Time taken to sort %d elements: %f seconds\n", n, cpu_time_used);

free(arr); 
return 0;
}
