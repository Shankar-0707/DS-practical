// AIM : Implement insertion, deletion and traversals (inorder, preorder and postorder) on binary
// search tree with the information in the tree about the details of an automobile (type, company, year
// of make).


// THEORY : Binary Search Tree ek binary tree hai jisme har node ki left subtree mein unse chhote
// values aur right subtree mein unse bade values hote hain. BST ka use data ko organize karne,
// insertion, deletion, aur searching ke liye hota hai.
// Node Structure
// • Automobile: Contains type, company, year of make.
// • Node: Contains automobile data and pointers to left and right children.


// ALGORITHM :
//  Insertion:
// • Compare the value to be inserted with the current node.
// • If it's less, move to the left child; if greater, move to the right child.
// • Insert the node when you reach a NULL pointer.
// Deletion:
// • Find the node to be deleted.
// • If the node has no children, simply remove it.
// • If it has one child, link its parent to its child.
// • If it has two children, find the inorder successor (minimum in the right subtree) and replace
// the node's value.
// Traversals:
// • Inorder: Left, Root, Right.
// • Preorder: Root, Left, Right.
// • Postorder: Left, Right, Root.


// SOURCE CODE -


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Structure for Automobile
struct Automobile {
char type[20];
char company[20];
int year;
};
// Structure for a Node in the BST
struct Node {
struct Automobile data;
struct Node* left;
struct Node* right;
};
// Function to create a new Node
struct Node* createNode(struct Automobile autoData) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = autoData;
newNode->left = newNode->right = NULL;
return newNode;
}
// Insertion Function
struct Node* insert(struct Node* root, struct Automobile autoData) {
if (root == NULL) {
return createNode(autoData);
}
if (autoData.year < root->data.year) {
root->left = insert(root->left, autoData);
} else {
root->right = insert(root->right, autoData);
}
return root;
}
// Deletion Function
struct Node* deleteNode(struct Node* root, int year) {
if (root == NULL) return root;
if (year < root->data.year) {
root->left = deleteNode(root->left, year);
} else if (year > root->data.year) {
root->right = deleteNode(root->right, year);
} else {
if (root->left == NULL) {
struct Node* temp = root->right;
free(root);
return temp;
} else if (root->right == NULL) {
struct Node* temp = root->left;
free(root);
return temp;
}
struct Node* temp = root->right;
while (temp && temp->left != NULL) temp = temp->left;
root->data = temp->data;
root->right = deleteNode(root->right, temp->data.year);
}
return root;
}
// Inorder Traversal
void inorder(struct Node* root) {
if (root != NULL) {
inorder(root->left);
printf("Type: %s, Company: %s, Year: %d\n", root->data.type, root->data.company, root->data.year);
inorder(root->right);
}
}
// Preorder Traversal
void preorder(struct Node* root) {
if (root != NULL) {
printf("Type: %s, Company: %s, Year: %d\n", root->data.type, root->data.company, root->data.year);
preorder(root->left);
preorder(root->right);
}
}
// Postorder Traversal
void postorder(struct Node* root) {
if (root != NULL) {
postorder(root->left);
postorder(root->right);
printf("Type: %s, Company: %s, Year: %d\n", root->data.type, root->data.company, root->data.year);
}
}
// Main Function
int main() {
struct Node* root = NULL;
struct Automobile auto1 = {"Sedan", "Toyota", 2020};
struct Automobile auto2 = {"SUV", "Honda", 2018};
struct Automobile auto3 = {"Hatchback", "Ford", 2019};
root = insert(root, auto1);
root = insert(root, auto2);
root = insert(root, auto3);
printf("Inorder Traversal:\n");
inorder(root);
printf("\nPreorder Traversal:\n");
preorder(root);
printf("\nPostorder Traversal:\n");
postorder(root);
printf("\nDeleting automobile from year 2018.\n");
root = deleteNode(root, 2018);
printf("\nInorder Traversal after deletion:\n");
inorder(root);
printf("Made by Shankar Jangid");
return 0;
}