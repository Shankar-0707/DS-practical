// AIM : Create a Binary Tree and perform Tree traversals (Preorder, Postorder, Inorder) using the
// concept of recursion


// THEORY : Binary Tree ek hierarchical data structure hai jisme har node ke paas maximum do
// children hote hain, jo left aur right kehlate hain. Tree ke kuch important traversals hain:
// 1. Inorder Traversal: Left, Root, Right.
// 2. Preorder Traversal: Root, Left, Right.
// 3. Postorder Traversal: Left, Right, Root


// ALGORITHM : Create a Node:
// • Allocate memory for a new node and assign data.
// Inorder Traversal:
// • Recursively visit left child, then the root, then right child.
// Preorder Traversal:
// • Visit the root, then recursively visit left child, then right child.
//  Postorder Traversal:
// • Recursively visit left child, then right child, then the root.


// SOURCE CODE -

#include <stdio.h>
#include <stdlib.h>
// Define a structure for a tree node
struct Node {
int data;
struct Node* left;
struct Node* right;
};
// Function to create a new node
struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->left = newNode->right = NULL;
return newNode;
}
// Inorder Traversal
void inorder(struct Node* root) {
if (root != NULL) {
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}
}
// Preorder Traversal
void preorder(struct Node* root) {
if (root != NULL) {
printf("%d ", root->data);
preorder(root->left);
preorder(root->right);
}
}
// Postorder Traversal
void postorder(struct Node* root) {
if (root != NULL) {
postorder(root->left);
postorder(root->right);
printf("%d ", root->data);
}
}
// Main function
int main() {
struct Node* root = createNode(1);
root->left = createNode(2);
root->right = createNode(3);
root->left->left = createNode(4);
root->left->right = createNode(5);
printf("Inorder Traversal: ");
inorder(root);
printf("\n");
printf("Preorder Traversal: ");
preorder(root);
printf("\n");
printf("Postorder Traversal: ");
postorder(root);
printf("\n");
printf("Made by Shankar Jangid");
return 0;
}