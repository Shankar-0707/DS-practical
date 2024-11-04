// AIM : Implement the searching using hashing method.

// THEORY : Hashing: Data ko ek fixed-size array (hash table) mein store karna. Hash function use
// karke element ka index calculate karte hain. Isse search operations O(1) time complexity mein
// hoti hain, agar collision handling sahi se kiya jaye.


// ALGORITHM :
// Hash Function: Input element ko integer value mein convert karo (modulus operation ka use
// karke).
//  Insertion:
// • Calculate index using the hash function.
// • Store the element at that index. Handle collisions using chaining (linked list) or open
// addressing.
//  Searching:
// • Calculate index using the hash function.
// • Check if the element exists at that index. If collision, check the linked list (if using chaining).


// SOURCE CODE –

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10
// Node for handling collisions using chaining
struct Node {
int data;
struct Node* next;
};
// Hash table
struct Node* hashTable[SIZE];
// Hash function
int hashFunction(int key) {
return key % SIZE; // Simple modulus hash function
}
// Insert function
void insert(int key) {
int index = hashFunction(key);
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = key;
newNode->next = hashTable[index];
hashTable[index] = newNode;
}
// Search function
int search(int key) {
int index = hashFunction(key);
struct Node* temp = hashTable[index];
while (temp) {
if (temp->data == key) return 1; // Found
temp = temp->next;
}
return 0; // Not found
}
// Main function
int main() {
int keys[] = {15, 11, 27, 8, 12};
int n = sizeof(keys) / sizeof(keys[0]);
// Inserting keys into the hash table
for (int i = 0; i < n; i++) {
insert(keys[i]);
}
// Searching for keys
int searchKey = 27;
if (search(searchKey))
printf("%d found in hash table.\n", searchKey);
else
printf("%d not found in hash table.\n", searchKey);
searchKey = 20;
if (search(searchKey))
printf("%d found in hash table.\n", searchKey);
else
printf("%d not found in hash table.\n", searchKey);
printf("\n Made by Shankar Jangid");
return 0;
}