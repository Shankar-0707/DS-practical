// AIM : Perform Linear Search and Binary Search on an array. Description of programs:
// a. Read an array of type integer.
// b. Input element from user for searching.
// c. Search the element by passing the array to a function and then returning the
// position of the element from the function else return -1 if the element is not found.
// d. Display the position where the element has been found.


// THEORY :
//  Linear Search: Array ke elements ko sequentially check karte hain jab tak desired element na mil
// jaye. Isme time complexity O(n) hoti hai.
// Binary Search: Sorted array mein desired element ko find karne ke liye divide-and-conquer approach
// use karte hain. Isme time complexity O(log n) hoti hai.


// ALGORITHM :
// Linear Search Algorithm:
// • Iterate through each element of the array.
// • Compare the element with the target.
// • If found, return the index; else return -1.
//  Binary Search Algorithm:
// • Sort the array if it is not sorted.
// • Set two pointers: low at the start and high at the end.
// • Find the middle element. If it matches the target, return the index.
// • If the target is less than the middle element, search in the left half; otherwise, search in the
// right half.


// SOURCE CODE -


#include <stdio.h>
// Function prototypes
int linearSearch(int arr[], int n, int target);
int binarySearch(int arr[], int n, int target);
// Linear Search function
int linearSearch(int arr[], int n, int target) {
for (int i = 0; i < n; i++) {
if (arr[i] == target) return i; // Element found
}
return -1; // Element not found
}
// Binary Search function
int binarySearch(int arr[], int n, int target) {
int low = 0, high = n - 1;
while (low <= high) {
int mid = low + (high - low) / 2;
if (arr[mid] == target) return mid; // Element found
if (arr[mid] < target) low = mid + 1; // Search right half
else high = mid - 1; // Search left half
}
return -1; // Element not found
}
// Main function
int main() {
int arr[] = {12, 34, 23, 45, 67}; // Example array
int n = sizeof(arr) / sizeof(arr[0]);
int target;
// Linear Search
printf("Enter element to search (Linear Search): ");
scanf("%d", &target);
int linearResult = linearSearch(arr, n, target);
if (linearResult != -1)
printf("Element found at index %d (Linear Search)\n", linearResult);
else
printf("Element not found (Linear Search)\n");
// Binary Search (Requires sorted array)
// Sort the array for binary search
int sortedArr[] = {12, 23, 34, 45, 67}; // Sorted version of the above array
printf("Enter element to search (Binary Search): ");
scanf("%d", &target);
int binaryResult = binarySearch(sortedArr, n, target);
if (binaryResult != -1)
printf("Element found at index %d (Binary Search)\n", binaryResult);
else
printf("Element not found (Binary Search)\n");
printf(" \n Made by Shankar Jangid");
return 0;
}