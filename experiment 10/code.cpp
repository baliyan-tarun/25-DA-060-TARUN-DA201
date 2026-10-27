#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);

    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int src;
    cin >> src;

    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i < V; i++) {
        bool updated = false;

        for (auto e : edges) {
            if (dist[e.u] != INT_MAX &&
                dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                updated = true;
            }
        }

        if (!updated)
            break;
    }

    for (auto e : edges) {
        if (dist[e.u] != INT_MAX &&
            dist[e.u] + e.w < dist[e.v]) {
            cout << "Negative weight cycle detected\n";
            return 0;
        }
    }

    cout << "Shortest distances from source " << src << ":\n";

    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << i << " : INF\n";
        else
            cout << i << " : " << dist[i] << "\n";
    }

    return 0;
}