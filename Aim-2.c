// AIM: Create a linked list with nodes having information about a student and perform
// a. Insert a new node at specified position. b. Delete of a node with the roll number
// of student specified. c. Reversal of that linked list. 

// THEORY: A linked list is a linear data structure that consists of a series of nodes
// connected by pointers (in C or C++) or references (in Java, Python and JavaScript). Each
// node contains data and a pointer/reference to the next node in the list. Unlike arrays,
// linked lists allow for efficient insertion or removal of elements from any position in the
// list, as the nodes are not stored contiguously in memory. A linked list is a linear data
// structure that consists of a series of nodes connected by pointers or references Each
// node contains data and a pointer/reference to the next node in the list. Unlike arrays,
// linked lists allow for efficient insertion or removal of elements from any position in the
// list, as the nodes are not stored contiguously in memory. 

// Linked List Applications
// • Implementing stacks and queues using linked lists.
// • Using linked lists to handle collisions in hash tables.
// • Representing graphs using linked lists.
// • Allocating and deallocating memory dynamically


// ALGORITHM:
// Step 1) Create a Node, Allocate Memory, Initialize Node and return node.
// Step 2) Insert a Node at a Specified Position, Create New Node
// Step 3)Handle Insertion at Head:
// • If position is 0, set the new node's next to the current head.
// • Update the head to point to the new node.
// Step 4)Insert at Other Positions:
// • Traverse the list to find the node just before the desired position.
// • Set the new node's next to the next node of the current node.
// • Update the current node’s next to point to the new node.
// Step 5)Delete a Node by Roll Number,Find the Node:
// • Traverse the list to find the node with the specified roll number.
// • Keep track of the previous node.
// Step 6)Delete the Node:
// • If the node is the head, update head to the next node.
// • Otherwise, set the previous node’s next to the next node of the current node.
// • Free the memory of the current node.
// Step 7)Handle Node Not Found:
// • If the node with the specified roll number is not found, print an error message.
// Step 8)Reverse the Linked List
// • Set prev to NULL, current to head, and next to NULL.
// Step 9)Reverse Links:
// • Iterate through the list:
// • Store the next node.
// • Set the current node's next to prev.
// • Move prev to the current node. • Move current to the next node.
// • After the loop, set head to prev.
// Step 10) Print the Linked List 

// CODE:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
 int rollNo;
 char name[50];
 struct Student* next;
};
struct Student* createNode(int rollNo, const char* name) {
 struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
 newNode->rollNo = rollNo;
 strcpy(newNode->name, name);
 newNode->next = NULL;
 return newNode;
}
// Function to insert a node at a specified position
void insertAtPosition(struct Student** head, int rollNo, const char* name, int position) {
 struct Student* newNode = createNode(rollNo, name);
 if (position == 0) { // Insert at the head
 newNode->next = *head;
 *head = newNode;
 return;
 }
 struct Student* temp = *head;
 for (int i = 0; i < position - 1 && temp != NULL; i++) {
 temp = temp->next;
 }
 if (temp == NULL) {
 printf("Position out of bounds for students .\n");
 free(newNode);
 } else {
 newNode->next = temp->next;
 temp->next = newNode;
 }
}
// Function to delete a node with a specified roll number
void deleteByRollNo(struct Student** head, int rollNo) {
 struct Student* temp = *head;
 struct Student* prev = NULL;
 // If the head node is to be deleted
 if (temp != NULL && temp->rollNo == rollNo) {
 *head = temp->next;
 free(temp);
 return;
 }
 // Search for the roll number to be deleted
 while (temp != NULL && temp->rollNo != rollNo) {
 prev = temp;
 temp = temp->next;
 }
 // If roll number was not found
 if (temp == NULL) {
 printf("Student with roll number %d are not found.\n", rollNo);
 return;
 }
 // Unlink the node
 prev->next = temp->next;
 free(temp);
}
// Function to reverse the linked list
void reverseList(struct Student** head) {
 struct Student* prev = NULL;
 struct Student* current = *head;
 struct Student* next = NULL;
 while (current != NULL) {
 next = current->next; // Store next node
 current->next = prev; // Reverse the link
 prev = current; // Move prev one step ahead
 current = next; // Move current one step ahead
 }
 *head = prev; // Update head to new first node
}
// Function to print the linked list
void printList(struct Student* head) {
 while (head != NULL) {
 printf("Roll No: %d, Name: %s\n", head->rollNo, head->name);
 head = head->next;
 }
}
// Main function
int main() {
 struct Student* head = NULL;
 // Insert students
 insertAtPosition(&head, 101, "Alice", 0);
 insertAtPosition(&head, 102, "Bob", 1);
 insertAtPosition(&head, 103, "Charlie", 1);

 printf("Initial Student List is given below:\n");
 printList(head);
 // Delete a student by roll number
 printf("\nDeleting student with roll number 102:\n");
 deleteByRollNo(&head, 102);
 printList(head);
 // Reverse the linked list
 printf("\nReversing the Student List:\n");
 reverseList(&head);
 printList(head);
 // Freeing the remaining nodes
 while (head != NULL) {
 struct Student* temp = head;
 head = head->next;
 free(temp);
 }
 return 0;
}
 