// AIM : Create a Linear Queue using Linked List and implement different operations such as Insert,
// Delete, and Display the queue elements

// THEORY : Queue ek linear data structure hai jo FIFO (First In, First Out) principle par kaam karta hai.
// Isme first element jo insert hota hai, wo sabse pehle delete hota hai. Queue ki kuch basic operations
// hain:
// 1. Insert (Enqueue): Queue mein element add karna.
// 2. Delete (Dequeue): Queue se front element ko remove karna.
// 3. Display: Queue ke elements ko display karna.

// ALGROTHIM :

// Insert (Enqueue) Operation:
// • Create a new node.
// • If the queue is empty, set both front and rear to the new node.
// • If the queue is not empty, link the current rear node to the new node and update rear to
// point to the new node.
// Delete (Dequeue) Operation:
// • Check if the queue is empty. If yes, return an error.
// • Store the front node's data.
// • Update the front pointer to the next node.
// • If the queue becomes empty after the operation, set rear to NULL.
//  Display Operation:
// • Start from the front node and print the data of each node until you reach the end.

// SOURCE CODE -
#include <stdio.h>
#include <stdlib.h>
// Define a structure for the queue node
struct Node {
int data;
struct Node* next;
};
// Define a structure for the queue
struct Queue {
struct Node* front;
struct Node* rear;
};
// Function to create a queue
struct Queue* createQueue() {
struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
queue->front = queue->rear = NULL;
return queue;
}
// Enqueue operation
void enqueue(struct Queue* queue, int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
if (queue->rear == NULL) {
// If queue is empty, then new node is both front and rear
queue->front = queue->rear = newNode;
printf(" %d enqueued to queue\n", data);
return;
}
// Add the new node at the end of the queue and update rear
queue->rear->next = newNode;
queue->rear = newNode;
printf(" %d enqueued to queue\n", data);
}
// Dequeue operation
int dequeue(struct Queue* queue) {
if (queue->front == NULL) {
printf("Queue is empty, cannot dequeue\n");
return -1; // Return -1 if queue is empty
}
int dequeuedData = queue->front->data;
struct Node* temp = queue->front;
queue->front = queue->front->next;
if (queue->front == NULL) {
// If front becomes NULL, then update rear as NULL
queue->rear = NULL;
}
free(temp);
return dequeuedData;
}
// Display operation
void display(struct Queue* queue) {
struct Node* current = queue->front;
if (current == NULL) {
printf("Queue is empty\n");
return;
}
printf("Queue elements: ");
while (current != NULL) {
printf("%d ", current->data);
current = current->next;
}
printf("\n");
}
// Main function
int main() {
printf("Made by Shankar Jangid");
struct Queue* queue = createQueue();
enqueue(queue, 10);
enqueue(queue, 20);
enqueue(queue, 30);
display(queue);
printf("%d dequeued from queue\n", dequeue(queue));
display(queue) ;
return 0; }