//NAVYA GUPTA 25/DA/047
#include <iostream>
#include <vector>
using namespace std;

// DFS function
void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    // Visit all outgoing neighbours
    for (int neighbour : adj[node]) {
        if (!visited[neighbour]) {
            DFS(neighbour, adj, visited);
        }
    }
}

int main() {
    cout<<"NAVYA GUPTA ROLL NO 25/DA/047\n";
    cout<<"CONNECTED COMPONENTS OF DIRECTED GRAPH\n";
    int V, E;

    cout << "Enter vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);

    // Take directed edges
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        // Directed edge: u -> v
        adj[u].push_back(v);
    }

    vector<bool> visited(V, false);

    int components = 0;

    // Start DFS from every unvisited vertex
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            components++;

            cout << "Component " << components << ": ";
            DFS(i, adj, visited);
            cout << endl;
        }
    }

    cout << "Total Components = " << components;

    return 0;
}