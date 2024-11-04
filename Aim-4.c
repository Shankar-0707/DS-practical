// AIM: Create a circular linked list having information about a college and perform
// insertion at front and deletion at end.


// THEORY: A circular linked list is a variation of a linked list in which the last node points
// back to the first node instead of pointing to NULL. This structure allows for a
// continuous traversal of the list without needing to check for a NULL terminator, making
// it particularly useful in scenarios where the data is cyclically accessed.
// Characteristics:
// • No NULL Nodes: Unlike traditional linked lists, there are no NULL pointers; each
// node points to another node.
// • Traversal: You can start from any node and traverse the entire list back to the
// starting node.
// • Efficient Operations: Insertions and deletions can be more efficient as we can
// manipulate the links without needing to traverse back to the head node.


// ALGORITHM:

// 1. Insertion at the Front
//  Create a new node with the provided data.  If the list is empty (i.e., the head
// is NULL):
//  Set the new node's next pointer to point to itself.
//  Update the head pointer to the new node.
//  If the list is not empty:
//  Traverse to the last node (the node whose next pointer points to the head).
//  Update the last node’s next pointer to point to the new node.
//  Set the new node’s next pointer to the current head.
//  Update the head pointer to the new node.
// 2. Deletion at the End
//  If the list is empty (i.e., the head is NULL), print an error message and return.
//  If the list has only one node (i.e., the next pointer of the head points to itself):
//  Free the node and set the head to NULL.
//  If there are multiple nodes:
//  Initialize two pointers, temp (set to head) and prev (set to NULL).
//  Traverse the list to find the last node by moving temp until temp->next points to
// the head.
//  Update prev->next to point to the head, effectively removing the last node from
// the list.
// Free the memory of the last node.
// 3. Print List
//  If the head is NULL, print that the list is empty.
//  Start from the head and traverse using a temporary pointer.
//  Continue until the temporary pointer points back to the head.
//  Print each node’s data during the traversal. 


// CODE:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Define the structure for a college node
struct College {
 int id;
 char name[50];
 struct College* next;
};
// Function to create a new college node
struct College* createNode(int id, const char* name) {
 struct College* newNode = (struct College*)malloc(sizeof(struct
College));
 newNode->id = id;
 strcpy(newNode->name, name);
 newNode->next = newNode; // Point to itself
 return newNode;
}
// Function to insert a node at the front of the circular linked list
void insertAtFront(struct College** head, int id, const char* name) {
 struct College* newNode = createNode(id, name);

 if (*head == NULL) { // If the list is empty
 *head = newNode;
 } else {
 struct College* temp = *head;

 // Traverse to the last node
 while (temp->next != *head) {
 temp = temp->next;
 }

 temp->next = newNode; // Link last node to new node
 }

 newNode->next = *head; // Link new node to head
 *head = newNode; // Update head to new node
}
// Function to delete a node at the end of the circular linked list
void deleteAtEnd(struct College** head) {
 if (*head == NULL) { // If the list is empty
 printf("The list is empty, nothing to delete.\n");
 return;
 }
 struct College* temp = *head;
 struct College* prev = NULL;
 // If there's only one node
 if (temp->next == *head) {
 free(temp);
 *head = NULL; // Update head to NULL
 return;
 }
 // Traverse to the last node
 while (temp->next != *head) {
 prev = temp;
 temp = temp->next;
 }
 // Unlink the last node
 prev->next = *head; // Link second last node to head
 free(temp); // Free memory
}
// Function to print the circular linked list
void printList(struct College* head) {
 if (head == NULL) {
 printf("The list is empty.\n");
 return;
 }

 struct College* temp = head;
 do {
 printf("College ID: %d, Name: %s\n", temp->id, temp->name);
 temp = temp->next;
 } while (temp != head);
}
// Main function
int main() {
 struct College* head = NULL;
 // Insert colleges at the front
 insertAtFront(&head, 1, "Engineering College");
 insertAtFront(&head, 2, "Arts College");
 insertAtFront(&head, 3, "Science College");
 printf("College List after insertions at front for user shankar:\n");
 printList(head);
 // Delete college at the end
 printf("\nDeleting college at the end for user shankar:\n");
 deleteAtEnd(&head);
 printList(head);
 // Clean up remaining nodes
 while (head != NULL) {
 struct College* temp = head;
 deleteAtEnd(&head);
 }
 return 0;
}