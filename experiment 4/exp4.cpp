#include <iostream>
using namespace std;

const int MAX = 100;

void DFS(int v, int graph[MAX][MAX], int visited[], int n) {
    visited[v] = 1;
    cout << v << " ";

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i])
            DFS(i, graph, visited, n);
    }
}

int main() {
    int n, e;
    int graph[MAX][MAX] = {0};
    int visited[MAX] = {0};

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges:\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    cout << "Connected Components:\n";

    int component = 1;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cout << "Component " << component++ << ": ";
            DFS(i, graph, visited, n);
            cout << endl;
        }
    }

    return 0;
}