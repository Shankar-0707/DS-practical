// AIM: Create doubly linked list with nodes having information about an employee
// and perform Insertion at front of doubly linked list and perform deletion at end of
// that doubly linked list.


// THEORY: A doubly linked list is a data structure that consists of a set of nodes, each
// of which contains a value and two pointers, one pointing to the previous node in
// the list and one pointing to the next node in the list. This allows for efficient
// traversal of the list in both directions, making it suitable for applications where
// frequent insertions and deletions are required. Each node in a Doubly Linked List
// contains the data it holds, a pointer to the next node in the list, and a pointer to
// the previous node in the list. By linking these nodes together through the next and
// previous pointers, we can traverse the list in both directions (forward and
// backward), which is a key feature of a Doubly Linked List.

// ALGORITHM:

// Step 1)Define Node Structure:
// • Attributes: name, id, next, prev.
// Step 2)Create DoublyLinkedList Class:
// • Attribute: head (pointer to the first node).
// Step 3)Constructor:
// • Initialize head to nullptr.
// Step 4)Insert at Front:
// • Create a new node.
// • If head is nullptr, set head to the new node.
// • Otherwise, update pointers to insert the new node at the front.
// Step 5)Delete at End:
// • If the list is empty, print a message.
// • Traverse to the last node, update pointers to remove it, and delete it.
// Step 6)Display List:
// • Traverse from head to the end, printing id and name of each node.

// Step 7)Destructor:
// • Delete all nodes to free memory.
// Step 8)Main Function:
// • Create a list instance, insert employees, display the list, delete the last
// employee, and display again.

// CODE:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Define the structure for an employee
struct Employee {
 int id;
 char name[50];
 struct Employee* next;
 struct Employee* prev;
};
// Function to create a new employee node
struct Employee* createNode(int id, const char* name) {
 struct Employee* newNode = (struct Employee*)malloc(sizeof(struct Employee));
 newNode->id = id;
 strcpy(newNode->name, name);
 newNode->next = NULL;
 newNode->prev = NULL;
 return newNode;
}
// Function to insert a node at the front
void insertAtFront(struct Employee** head, int id, const char* name) {
 struct Employee* newNode = createNode(id, name);
 newNode->next = *head; // Make next of new node as head
 if (*head != NULL) {
 (*head)->prev = newNode; // Change prev of head node to new node
 }
 *head = newNode; // Move head to point to the new node
}
// Function to delete a node at the end
void deleteAtEnd(struct Employee** head) {
 if (*head == NULL) { // If the list is empty
 printf("The list is empty, nothing to delete.\n");
 return;
 }
 struct Employee* temp = *head;
 // Traverse to the last node
 while (temp->next != NULL) {
 temp = temp->next;
 }
 // If the list contains only one node
 if (temp == *head) {
 free(temp);
 *head = NULL; // Update head to NULL
 } else {
 temp->prev->next = NULL; // Unlink the last node
 free(temp); // Free memory
 }
}
// Function to print the doubly linked list
void printList(struct Employee* head) {
 struct Employee* temp = head;
 while (temp != NULL) {
 printf("Employee ID: %d, Name: %s\n", temp->id, temp->name);
 temp = temp->next;
 }
}
// Main function
int main() {
 struct Employee* head = NULL;
 // Insert employees at the front
 insertAtFront(&head, 1, "Alice");
 insertAtFront(&head, 2, "Bob");
 insertAtFront(&head, 3, "Charlie");
 printf("Employee List after insertions at front for user shankar:\n");
 printList(head);
 // Delete employee at the end
 printf("\nDeleting employee at the end for user shankar:\n");
 deleteAtEnd(&head);
 printList(head);
 // Clean up remaining nodes
 while (head != NULL) {
 struct Employee* temp = head;
 head = head->next;
 free(temp);
 }
 return 0;
} 