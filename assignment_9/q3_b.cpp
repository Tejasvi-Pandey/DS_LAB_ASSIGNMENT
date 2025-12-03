#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;  
// (weight, node)

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pii>> graph(V);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});  // Undirected
    }

    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    vector<int> parent(V, -1);

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    key[0] = 0;           // Start from node 0
    pq.push({0, 0});      // (weight, node)

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;

        for (auto &edge : graph[u]) {
            int w = edge.first;
            int v = edge.second;

            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({w, v});
            }
        }
    }

    cout << "MST (Prim):\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i
             << "  weight = " << key[i] << "\n";

    return 0;
}
