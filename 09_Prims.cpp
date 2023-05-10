#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Structure to represent an edge
struct Edge {
    int source;
    int destination;
    int weight;

    Edge(int src, int dest, int w) : source(src), destination(dest), weight(w) {}
};

// Structure to represent a node in the graph
struct Node {
    int vertex;
    int weight;

    Node(int v, int w) : vertex(v), weight(w) {}
};

// Function to add an edge to the graph
void addEdge(vector<vector<Node>>& graph, int src, int dest, int weight) {
    graph[src].push_back(Node(dest, weight));
    graph[dest].push_back(Node(src, weight));
}

// Function to find the minimum spanning tree using Prim's algorithm
vector<Edge> primMST(const vector<vector<Node>>& graph, int numVertices) {
    // Create a priority queue to store the nodes
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    // Create a vector to track the visited nodes
    vector<bool> visited(numVertices, false);

    // Create a vector to store the minimum spanning tree edges
    vector<Edge> mst;

    // Start with the first node (0th vertex)
    int startNode = 0;
    visited[startNode] = true;

    // Add all the edges connected to the first node to the priority queue
    for (const Node& neighbor : graph[startNode]) {
        pq.push(neighbor);
    }

    // Explore the graph until all nodes are visited
    while (!pq.empty()) {
        // Get the node with the minimum weight
        Node current = pq.top();
        pq.pop();

        int vertex = current.vertex;
        int weight = current.weight;

        // If the node is already visited, skip it
        if (visited[vertex]) {
            continue;
        }

        // Mark the node as visited
        visited[vertex] = true;

        // Add the edge to the minimum spanning tree
        mst.push_back(Edge(vertex, weight, weight));

        // Add all the edges connected to the current node to the priority queue
        for (const Node& neighbor : graph[vertex]) {
            if (!visited[neighbor.vertex]) {
                pq.push(neighbor);
            }
        }
    }

    // Return the minimum spanning tree
    return mst;
}

int main() {
    int numVertices, numEdges;

    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<Node>> graph(numVertices);

    cout << "Enter the source, destination, and weight of each edge:\n";
    for (int i = 0; i < numEdges; i++) {
        int src, dest, weight;
        cout << "Edge " << i + 1 << ":\n";
        cout << "Source: ";
        cin >> src;
        cout << "Destination: ";
        cin >> dest;
        cout << "Weight: ";
        cin >> weight;
        cout << endl;
        addEdge(graph, src, dest, weight);
    }

    vector<Edge> mst = primMST(graph, numVertices);

    cout << "Minimum Spanning Tree Edges:\n";
    for (const Edge& edge : mst) {
        cout << edge.source << " - " << edge.destination << " (Weight: " << edge.weight << ")\n";
    }

    return 0;
}
