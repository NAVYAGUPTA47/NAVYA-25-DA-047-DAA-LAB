//NAVYA GUPTA 25/DA/047
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, weight;
};

int parent[10];

int find(int x)
{
    while (parent[x] != x)
        x = parent[x];

    return x;
}

int main()
{   cout<<"NAVYA GUPTA ROLL NO 25/DA/047\n";
    cout<<"SOLVING MST USING KRUSKAL\n";
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    Edge edges[20];

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < e; i++)
    {
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].weight;
    }

    // Sort edges according to weight
    sort(edges, edges + e, [](Edge a, Edge b)
    {
        return a.weight < b.weight;
    });

    // Initially every vertex is its own parent
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int total = 0;
    int count = 0;

    cout << "Edges in MST:\n";

    for (int i = 0; i < e && count < n - 1; i++)
    {
        int u = find(edges[i].u);
        int v = find(edges[i].v);

        // If parents are different, no cycle
        if (u != v)
        {
            cout << edges[i].u << " - "
                 << edges[i].v << " : "
                 << edges[i].weight << endl;

            total += edges[i].weight;
            parent[u] = v;
            count++;
        }
    }

    cout << "Minimum cost = " << total << endl;

    return 0;
}