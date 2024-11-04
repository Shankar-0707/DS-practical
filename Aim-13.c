// Aim : Create a graph and perform DFS and BFS traversals.


// Theory :
// Graph: Nodes (vertices) ka collection aur unhe connect karne wale edges. Graphs
// ko directed ya undirected, weighted ya unweighted ke roop mein classify kiya ja
// sakta hai.
//  DFS (Depth First Search): Ek vertex se shuru hota hai aur jitna ho sake us vertex
// ke descendants ko visit karta hai. Jab koi aur unvisited vertex nahi bacha, tab
// backtrack karta hai.
//  BFS (Breadth First Search): Ek vertex se shuru hota hai aur us vertex ke sabhi
// adjacent vertices ko visit karta hai, fir unke adjacent vertices ko visit karta hai.
// Isme queue ka use hota hai.


// ALG0RITHM :
// DFS Algorithm:
// • Start from a selected node.
// • Mark the node as visited.
// • Recursively visit all adjacent unvisited nodes.
// BFS Algorithm:
// • Start from a selected node.
// • Mark the node as visited and enqueue it.
// • While the queue is not empty, dequeue a node, visit it, and enqueue all its
// unvisited adjacent nodes.




// Source code –


#include <stdio.h>
#include <stdlib.h>
#define MAX 10
// Graph structure
struct Graph {
int vertices;
int adj[MAX][MAX]; // Adjacency matrix
};
// Function prototypes
void DFS(struct Graph* g, int visited[], int vertex);
void BFS(struct Graph* g, int start);
int main() {
struct Graph g = {5, {{0, 1, 1, 1, 0}, {1, 0, 0, 1, 1}, {1, 0, 0, 0, 1}, {1, 1, 0, 0, 1}, {0, 1, 1, 1, 0}}};
// DFS
int visited[MAX] = {0}; // Reset visited array
printf("DFS Traversal: ");
DFS(&g, visited, 0); // Starting from vertex 0
printf("\n");
// BFS
printf("BFS Traversal: ");
BFS(&g, 0); // Starting from vertex 0
printf("\n");
printf("\n Made by Shankar Jangid");
return 0;
}
// DFS implementation
void DFS(struct Graph* g, int visited[], int vertex) {
visited[vertex] = 1; // Mark the vertex as visited
printf("%d ", vertex);
for (int i = 0; i < g->vertices; i++) {
if (g->adj[vertex][i] && !visited[i]) { // If there's an edge and not visited
DFS(g, visited, i);
}
}
}
// BFS implementation
void BFS(struct Graph* g, int start) {
int queue[MAX], front = -1, rear = -1;
int visited[MAX] = {0};
visited[start] = 1; // Mark the start vertex as visited
queue[++rear] = start; // Enqueue the start vertex
while (front < rear) {
int current = queue[++front]; // Dequeue
printf("%d ", current);
for (int i = 0; i < g->vertices; i++) {
if (g->adj[current][i] && !visited[i]) { // If there's an edge and not visited
visited[i] = 1; // Mark as visited
queue[++rear] = i; }}}} // Enqueue  