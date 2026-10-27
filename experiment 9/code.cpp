#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int src;
    cin >> src;

    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d != dist[u])
            continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
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