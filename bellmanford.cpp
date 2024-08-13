/*
 Name:Parth Anand Bramhecha
 Class:Te-09  Batch:L-9
 Roll number:33115
 Date:7/8/24
*/

#include <iostream>
#include <climits> // For INT_MAX
using namespace std;

// Struct for edge of graph
struct Edge {
int u; // Start vertex
int v; // End vertex
int w; // Weight of edge (u, v)
};

// Graph structure
struct Graph {
struct Edge* edge; // Array of edges
};

// Function to print the distance array
void printArr(int arr[], int size) {
for (int i = 0; i < size; i++) {
cout << arr[i] << " ";
}
cout << endl;
}

// Function to read edge data from user
void readEdges(struct Graph* graph, int E) {
cout << "Enter the edges in the format u v w (where u is start vertex, v is end vertex, and w is weight):" << endl;
for (int i = 0; i < E; i++) {
cout << "Edge " << i + 1 << ": ";
cin >> graph->edge[i].u >> graph->edge[i].v >> graph->edge[i].w;
}
}

// Bellman-Ford algorithm implementation
void BellmanFord(struct Graph* graph, int src, int V, int E) {
int dist[V]; // Distance array

// Initialize distances from source to all vertices as INFINITE
for (int i = 0; i < V; i++) {
dist[i] = INT_MAX;
}
dist[src] = 0;

// Relax all edges |V| - 1 times
for (int i = 1; i <= V - 1; i++) {
for (int j = 0; j < E; j++) {
int u = graph->edge[j].u;
int v = graph->edge[j].v;
int w = graph->edge[j].w;
if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
dist[v] = dist[u] + w;
}
}
}

// Check for negative-weight cycles
for (int i = 0; i < E; i++) {
int u = graph->edge[i].u;
int v = graph->edge[i].v;
int w = graph->edge[i].w;
if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
cout << "Graph contains negative weight cycle" << endl;
return;
}
}

// Print the distance array
printArr(dist, V);
}

int main() {
int V, E;
cout << "Enter number of vertices: ";
cin >> V;
cout << "Enter number of edges: ";
cin >> E;

struct Graph* graph = new Graph;
graph->edge = new Edge[E];

// Read edge data
readEdges(graph, E);

int src;
cout << "Enter the source vertex: ";
cin >> src;

// Call Bellman-Ford algorithm
BellmanFord(graph, src, V, E);

// Clean up memory
delete[] graph->edge;
delete graph;

return 0;
}

