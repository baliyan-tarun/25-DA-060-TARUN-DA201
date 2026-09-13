#include <iostream>
using namespace std;

const int MAX = 100;

int graph[MAX][MAX];
int visited[MAX], disc[MAX], low[MAX], parent[MAX];
bool articulation[MAX];
int timer = 0;
int n;

void DFS(int u)
{
    visited[u] = 1;
    disc[u] = low[u] = ++timer;

    int children = 0;

    for (int v = 0; v < n; v++)
    {
        if (graph[u][v])
        {
            if (!visited[v])
            {
                children++;
                parent[v] = u;

                DFS(v);

                low[u] = min(low[u], low[v]);

                if (parent[u] == -1 && children > 1)
                    articulation[u] = true;

                if (parent[u] != -1 && low[v] >= disc[u])
                    articulation[u] = true;
            }
            else if (v != parent[u])
            {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
}

int main()
{
    int edges;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges:\n";

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }

    for (int i = 0; i < n; i++)
        parent[i] = -1;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            DFS(i);
    }

    cout << "Cut Vertices: ";

    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (articulation[i])
        {
            cout << i << " ";
            found = true;
        }
    }

    if (!found)
        cout << "None";

    cout << endl;

    return 0;
}