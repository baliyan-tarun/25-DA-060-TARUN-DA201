#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

int findParent(int x, vector<int>& parent) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x], parent);
}

void unite(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = findParent(a, parent);
    b = findParent(b, parent);

    if (a == b) return;

    if (rank[a] < rank[b])
        parent[a] = b;
    else if (rank[a] > rank[b])
        parent[b] = a;
    else {
        parent[b] = a;
        rank[a]++;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    vector<int> parent(n), rank(n, 0);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int cost = 0;

    for (auto e : edges) {
        if (findParent(e.u, parent) != findParent(e.v, parent)) {
            unite(e.u, e.v, parent, rank);
            cout << e.u << " - " << e.v << " : " << e.w << '\n';
            cost += e.w;
        }
    }

    cout << "Minimum Cost: " << cost << '\n';

    return 0;
}