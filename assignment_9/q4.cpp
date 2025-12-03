#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

typedef pair<int, int> pii;  
// first = distance, second = node

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pii>> graph(V);
    // each entry: graph[u] = { (weight, v), ... }

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});  // remove if directed
    }

    int source;
    cin >> source;

    vector<int> dist(V, numeric_limits<int>::max());
    dist[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d != dist[u]) continue;  // ignore old entries

        for (auto &edge : graph[u]) {
            int weight = edge.first;
            int v = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < V; i++)
        cout << "Node " << i << " --> " << dist[i] << "\n";

    return 0;
}
