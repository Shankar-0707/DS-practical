// AIM : Implement Selection Sort, Bubble Sort, Insertion sort, Merge sort, Quick sort, and Heap
// Sort using array as a data structure.


// THEORY :
// Selection Sort: Elements ko iterate karke sabse chhota (ya bada) element find karke usse swap
// karte hain.
//  Bubble Sort: Adjacent elements ko compare karke swap karte hain agar wo sahi order mein
// nahi hain. Yeh process tab tak hota hai jab tak array sorted na ho.
// Insertion Sort: Array ko sorted aur unsorted parts mein divide karke har element ko correct
// position par insert karte hain.
// Merge Sort: Divide-and-conquer method ka use karke array ko do halves mein divide karte
// hain, unhe sort karte hain, aur phir merge karte hain.
//  Quick Sort: Ek pivot element choose karte hain, array ko pivot se chhote aur bade elements
// mein divide karte hain, aur phir recursively sort karte hain.
//  Heap Sort: Array ko heap structure mein convert karte hain, sabse bada (ya chhota) element
// extract karte hain aur array ko sort karte hain.


// ALGORITHM :
//  Selection Sort:
// Iterate through the array, find the minimum element, and swap it with the current position.
//  Bubble Sort:
// Compare adjacent elements and swap them if they are in the wrong order. Repeat until sorted.
// Insertion Sort:
// Start from the second element, compare it with elements before it, and insert it in the correct
// position.
//  Merge Sort:
// Divide the array into two halves, recursively sort each half, and merge them back.
//  Quick Sort:
// Choose a pivot, partition the array into elements less than and greater than the pivot, and
// recursively sort the partitions.
//  Heap Sort:
// Build a max heap, repeatedly extract the maximum element and rebuild the heap.


// SOURCE CODE -


#include <stdio.h>
// Function prototypes
void selectionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSort(int arr[], int l, int r);
void quickSort(int arr[], int low, int high);
void heapSort(int arr[], int n);
// Selection Sort
void selectionSort(int arr[], int n) {
for (int i = 0; i < n - 1; i++) {
int minIndex = i;
for (int j = i + 1; j < n; j++)
if (arr[j] < arr[minIndex]) minIndex = j;
int temp = arr[i]; arr[i] = arr[minIndex]; arr[minIndex] = temp;
}
}
// Bubble Sort
void bubbleSort(int arr[], int n) {
for (int i = 0; i < n - 1; i++)
for (int j = 0; j < n - i - 1; j++)
if (arr[j] > arr[j + 1]) {
int temp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = temp;
}
}
// Insertion Sort
void insertionSort(int arr[], int n) {
for (int i = 1; i < n; i++) {
int key = arr[i], j = i - 1;
while (j >= 0 && arr[j] > key) { arr[j + 1] = arr[j]; j--; }
arr[j + 1] = key;
}
}
// Merge Sort
void merge(int arr[], int l, int m, int r) {
int n1 = m - l + 1, n2 = r - m;
int L[n1], R[n2];
for (int i = 0; i < n1; i++) L[i] = arr[l + i];
for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
int i = 0, j = 0, k = l;
while (i < n1 && j < n2) {
if (L[i] <= R[j]) arr[k++] = L[i++];
else arr[k++] = R[j++];
}
while (i < n1) arr[k++] = L[i++];
while (j < n2) arr[k++] = R[j++];
}
void mergeSort(int arr[], int l, int r) {
if (l < r) {
int m = l + (r - l) / 2;
mergeSort(arr, l, m);
mergeSort(arr, m + 1, r);
merge(arr, l, m, r);
}
}
// Quick Sort
int partition(int arr[], int low, int high) {
int pivot = arr[high], i = (low - 1);
for (int j = low; j < high; j++) {
if (arr[j] < pivot) {
i++;
int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
}
}
int temp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = temp;
return i + 1;
}
void quickSort(int arr[], int low, int high) {
if (low < high) {
int pi = partition(arr, low, high);
quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
}
}
// Heap Sort
void heapify(int arr[], int n, int i) {
int largest = i, left = 2 * i + 1, right = 2 * i + 2;
if (left < n && arr[left] > arr[largest]) largest = left;
if (right < n && arr[right] > arr[largest]) largest = right;
if (largest != i) {
int temp = arr[i]; arr[i] = arr[largest]; arr[largest] = temp;
heapify(arr, n, largest);
}
}
void heapSort(int arr[], int n) {
for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
for (int i = n - 1; i >= 0; i--) {
int temp = arr[0]; arr[0] = arr[i]; arr[i] = temp;
heapify(arr, i, 0);
}
}
// Display function
void printArray(int arr[], int n) {
for (int i = 0; i < n; i++) printf("%d ", arr[i]);
printf("\n");
}
// Main function
int main() {
int arr1[] = {64, 25, 12, 22, 11}; // Selection Sort
int arr2[] = {64, 34, 25, 12, 22, 11}; // Bubble Sort
int arr3[] = {12, 11, 13, 5, 6}; // Insertion Sort
int arr4[] = {38, 27, 43, 3, 9, 82, 10}; // Merge Sort
int arr5[] = {10, 7, 8, 9, 1, 5}; // Quick Sort
int arr6[] = {12, 11, 13, 5, 6, 7}; // Heap Sort
printf("Selection Sort: ");
selectionSort(arr1, 5);
printArray(arr1, 5);
printf("Bubble Sort: ");
bubbleSort(arr2, 6);
printArray(arr2, 6);
printf("Insertion Sort: ");
insertionSort(arr3, 5);
printArray(arr3, 5);
printf("Merge Sort: ");
mergeSort(arr4, 0, 6 - 1);
printArray(arr4, 7);
printf("Quick Sort: ");
quickSort(arr5, 0, 5);
printArray(arr5, 6);
printf("Heap Sort: ");
heapSort(arr6, 6);
printArray(arr6, 6);
printf("\n Made by Shankar Jangid"); return 0; }