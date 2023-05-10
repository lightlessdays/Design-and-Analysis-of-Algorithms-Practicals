#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Function to perform Breadth-First Search
void BFS(vector<vector<int>>& graph, int startNode) {
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false); // Keep track of visited nodes
    queue<int> q; // Queue for BFS traversal

    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int currentNode = q.front();
        cout << currentNode << " ";
        q.pop();

        // Visit all adjacent nodes of the current node
        for (int i = 0; i < graph[currentNode].size(); i++) {
            int adjacentNode = graph[currentNode][i];
            if (!visited[adjacentNode]) {
                visited[adjacentNode] = true;
                q.push(adjacentNode);
            }
        }
    }
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<int>> graph(numNodes);

    cout << "Enter the edges in the format (u v):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    cout << "BFS traversal starting from node " << startNode << ": ";
    BFS(graph, startNode);

    return 0;
}
