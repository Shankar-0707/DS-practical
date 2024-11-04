// AIM : Create a stack and perform Push, Pop, Peek and Traverse operations on the stack using Linked
//  List.

// Thoery : Stack ek linear data structure hai jo LIFO (Last In, First Out) principle par kaam karta hai.
// Isme last item jo push hota hai, wo sabse pehle pop hota hai. Stack ki kuch basic operations hain:
// 1. Push: Stack mein element add karna.
// 2. Pop: Stack se top element ko remove karna.
// 3. Peek: Top element ko dekhna bina usse remove kiye.
// 4. Traverse: Stack ke elements ko display karna.

// Algorithm :

// Push Operation:
// • Create a new node.
// • Set the new node's next pointer to the current top node.
// • Update the top pointer to point to the new node.
//  Pop Operation:
// • Check if the stack is empty. If yes, return an error.
// • Store the top node's data.
// • Update the top pointer to the next node.
// • Return the stored data.
// Peek Operation:
// • Check if the stack is empty. If yes, return an error.
// • Return the data of the top node.
// Traverse Operation:
// • Start from the top node and print the data of each node until you reach the end.

// Source Code-
#include <stdio.h>
#include <stdlib.h>
// Define a structure for the stack node
struct Node {
int data;
struct Node* next;
};
// Define a structure for the stack
struct Stack {
struct Node* top;
};
// Function to create a stack
struct Stack* createStack() {
struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
stack->top = NULL;
return stack;
}
// Push operation
void push(struct Stack* stack, int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = stack->top;
stack->top = newNode;
printf(" %d pushed to stack\n", data);
}
// Pop operation
int pop(struct Stack* stack) {
if (stack->top == NULL) {
printf("Stack is empty, cannot pop\n");
return -1; // Return -1 if stack is empty
}
int poppedData = stack->top->data;
struct Node* temp = stack->top;
stack->top = stack->top->next;
free(temp);
return poppedData;
}
// Peek operation
int peek(struct Stack* stack) {
if (stack->top == NULL) {
printf("Stack is empty, cannot peek\n");
return -1; // Return -1 if stack is empty
}
return stack->top->data;
}
// Traverse operation
void traverse(struct Stack* stack) {
struct Node* current = stack->top;
if (current == NULL) {
printf("Stack is empty\n");
return;
}
printf("Stack elements: ");
while (current != NULL) {
printf("%d ", current->data);
current = current->next;
}
printf("\n");
}
// Main function
int main() {
printf("Made by Shankar Jangid");
struct Stack* stack = createStack();
push(stack, 10);
push(stack, 20);
push(stack, 30);
printf("Top element is %d\n", peek(stack));
traverse(stack);
printf("%d popped from stack\n", pop(stack));
printf("Top element is %d\n", peek(stack));
traverse(stack);
return 0;
}