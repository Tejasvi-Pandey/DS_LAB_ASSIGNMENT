#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x != y) {
            if (rank[x] < rank[y])
                parent[x] = y;
            else if (rank[x] > rank[y])
                parent[y] = x;
            else {
                parent[y] = x;
                rank[x]++;
            }
        }
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);

    for (int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    // Sort edges by weight
    sort(edges.begin(), edges.end(), 
        [](Edge a, Edge b) { return a.w < b.w; });

    DisjointSet ds(V);
    vector<Edge> mst;

    for (auto &e : edges) {
        if (ds.find(e.u) != ds.find(e.v)) {
            mst.push_back(e);
            ds.unite(e.u, e.v);
        }
    }

    cout << "MST (Kruskal):\n";
    for (auto &e : mst)
        cout << e.u << " - " << e.v << "  weight = " << e.w << "\n";

    return 0;
}
