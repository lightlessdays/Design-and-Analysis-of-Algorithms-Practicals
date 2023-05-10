#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to perform Depth-First Search
void DFS(vector<vector<int>>& graph, int startNode) {
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false); // Keep track of visited nodes
    stack<int> stk; // Stack for DFS traversal

    stk.push(startNode);

    while (!stk.empty()) {
        int currentNode = stk.top();
        stk.pop();

        if (!visited[currentNode]) {
            cout << currentNode << " ";
            visited[currentNode] = true;

            // Visit all adjacent nodes of the current node
            for (int i = 0; i < graph[currentNode].size(); i++) {
                int adjacentNode = graph[currentNode][i];
                if (!visited[adjacentNode]) {
                    stk.push(adjacentNode);
                }
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

    cout << "DFS traversal starting from node " << startNode << ": ";
    DFS(graph, startNode);

    return 0;
}
