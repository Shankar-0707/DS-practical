// AIM: Implement two stacks using single array.


// THEORY: A stack is a data structure that follows the Last In First Out (LIFO) principle,
// where the most recently added element is the first to be removed. Typically, stacks are
// implemented using linked lists or arrays. This implementation uses a single array to
// accommodate two stacks, effectively utilizing the available space.


// ALGORITHM:

// 1. Structure Definition
// Define a structure to hold the array and the two stack pointers.
// 2. Initialization
// Create a function to initialize the two stacks:
// • Set top1 to -1 (indicating that Stack 1 is empty).
// • Set top2 to MAX (indicating that Stack 2 is empty).
// 3. Push Operation
// • Push to Stack 1:
// o Check if top1 + 1 equals top2 (indicating overflow).
// o If not, increment top1 and place the element in arr[top1].
// • Push to Stack 2:
// o Check if top1 + 1 equals top2 (indicating overflow).
// o If not, decrement top2 and place the element in arr[top2].
// 4. Pop Operation
// • Pop from Stack 1:
// o Check if top1 is -1 (indicating underflow).
// o If not, return the element at arr[top1] and decrement top1.
// • Pop from Stack 2:
// o Check if top2 equals MAX (indicating underflow).
// o If not, return the element at arr[top2] and increment top2.
// 5. Display Stacks
// Traverse the array from 0 to top1 for Stack 1 and from MAX-1 to top2 for Stack 2,
// printing their elements.


// CODE:

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100 // Maximum size of the array
// Define the structure for two stacks
struct TwoStacks {
 int arr[MAX_SIZE]; // Array to store stack elements
 int top1; // Index for Stack 1
 int top2; // Index for Stack 2
};
// Function to create two stacks
struct TwoStacks* createStacks() {
 struct TwoStacks* stacks = (struct TwoStacks*)malloc(sizeof(struct
TwoStacks));
 stacks->top1 = -1; // Initialize Stack 1's top
 stacks->top2 = MAX_SIZE; // Initialize Stack 2's top
 return stacks;
}
// Function to check if Stack 1 is full
bool isFullStack1(struct TwoStacks* stacks) {
 return stacks->top1 + 1 == stacks->top2;
}
// Function to check if Stack 2 is full
bool isFullStack2(struct TwoStacks* stacks) {
 return stacks->top2 - 1 == stacks->top1;
}
// Function to check if Stack 1 is empty
bool isEmptyStack1(struct TwoStacks* stacks) {
 return stacks->top1 == -1;
}
// Function to check if Stack 2 is empty
bool isEmptyStack2(struct TwoStacks* stacks) {
 return stacks->top2 == MAX_SIZE;
}
// Function to push an element to Stack 1
void pushStack1(struct TwoStacks* stacks, int value) {
 if (isFullStack1(stacks)) {
 printf("Stack 1 is full. Cannot push %d\n", value);
 return;
 }
 stacks->arr[++stacks->top1] = value; // Increment top1 and push
value;
}
// Function to push an element to Stack 2
void pushStack2(struct TwoStacks* stacks, int value) {
 if (isFullStack2(stacks)) {
 printf("Stack 2 is full. Cannot push %d\n", value);
 return;
 }
 stacks->arr[--stacks->top2] = value; // Decrement top2 and push
value;
}
// Function to pop an element from Stack 1
int popStack1(struct TwoStacks* stacks) {
 if (isEmptyStack1(stacks)) {
 printf("Stack 1 is empty. Cannot pop\n");
 return -1; // Indicate failure
 }
 return stacks->arr[stacks->top1--]; // Return value and decrement

}
// Function to pop an element from Stack 2
int popStack2(struct TwoStacks* stacks) {
 if (isEmptyStack2(stacks)) {
 printf("Stack 2 is empty. Cannot pop\n");
 return -1; // Indicate failure
 }

}
// Function to print elements of Stack 1
void printStack1(struct TwoStacks* stacks) {
 printf("Stack 1: ");
 for (int i = 0; i <= stacks->top1; i++) {
 printf("%d ", stacks->arr[i]);
 }
 printf("\n");
}
// Function to print elements of Stack 2
void printStack2(struct TwoStacks* stacks) {
 printf("Stack 2: ");
 for (int i = MAX_SIZE - 1; i >= stacks->top2; i--) {
 printf("%d ", stacks->arr[i]);
 }
 printf("\n");
}
// Main function
int main() {
 struct TwoStacks* stacks = createStacks();
 // Push elements to Stack 1
 pushStack1(stacks, 10);
 pushStack1(stacks, 20);
 pushStack1(stacks, 30);
 // Push elements to Stack 2
 pushStack2(stacks, 40);
 pushStack2(stacks, 50);
 pushStack2(stacks, 60);
 // Print the stacks
 printStack1(stacks);
 printStack2(stacks);
 // Pop elements from Stack 1
 printf("Popped from Stack 1 for user shankar: %d\n",
popStack1(stacks));
 printStack1(stacks);
 // Pop elements from Stack 2
 printf("Popped from Stack 2 for user shankar: %d\n",
popStack2(stacks));
 printStack2(stacks);
 // Free the allocated memory
 free(stacks);

 return 0;
}
