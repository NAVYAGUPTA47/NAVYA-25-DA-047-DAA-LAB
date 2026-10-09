//NAVYA GUPTA 25/DA/047
#include <iostream>
using namespace std;

#define INF 9999
#define MAX 10

int main()
{   cout<<"NAVYA GUPTA ROLL NO 25/DA/047\n";
    cout<<"Single Source Shortest Path using Dijkstra's algorithm\n";
    int n, cost[MAX][MAX], dist[MAX], visited[MAX];
    int src, min, u;

    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter cost adjacency matrix:\n";
    // Read the adjacency matrix
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> cost[i][j];
            // Replace 0 with INF if no edge exists
            if (i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    cout << "Enter source vertex (0 to " << n - 1 << "): ";
    cin >> src;

    // Initialize distances and visited array
    for (int i = 0; i < n; i++)
    {
        dist[i] = cost[src][i];
        visited[i] = 0;
    }

    dist[src] = 0;
    visited[src] = 1;

    // Find shortest paths to all vertices
    for (int count = 1; count < n; count++)
    {
        min = INF;
        u = -1;
        // Find the unvisited vertex with minimum distance
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }
        if (u == -1)
            break;

        visited[u] = 1;

        // Update distances of adjacent vertices
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && cost[u][v] != INF && dist[u] != INF &&  dist[u] + cost[u][v] < dist[v])
            {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    // Display shortest distances from the source
    cout << "\nShortest distances from source vertex " << src << ":\n";

    for (int i = 0; i < n; i++)
    {
        cout << "To vertex " << i << " = ";

        if (dist[i] == INF)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }

    return 0;
}