//NAVYA GUPTA 25/DA/047
#include <iostream>
using namespace std;

int main()
{   cout<<"NAVYA GUPTA ROLL NO 25/DA/047\n";
    cout<<"SOLVING MST USING PRIMS\n";
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[10][10];

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    int visited[10] = {0};
    int edges = 0, total = 0;

    visited[0] = 1;

    cout << "Edges in MST:\n";

    while (edges < n - 1)
    {
        int min = 9999;
        int u = -1, v = -1;

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] && graph[i][j] != 0 &&
                        graph[i][j] < min)
                    {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        cout << u << " - " << v << " : " << min << endl;

        total += min;
        visited[v] = 1;
        edges++;
    }

    cout << "Minimum cost = " << total << endl;

    return 0;
}