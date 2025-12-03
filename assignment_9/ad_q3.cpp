#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

typedef pair<int, int> pii;  
// (time, node)

int main() {
    int N, E;
    cin >> N >> E;

    vector<vector<pii>> graph(N + 1);  
    // graph[u] = { (weight, v), ... }

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
    }

    int K;
    cin >> K;

    vector<int> dist(N + 1, numeric_limits<int>::max());
    dist[K] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, K});   // (time, starting node)

    while (!pq.empty()) {
        int time = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (time != dist[node]) continue;  // skip outdated

        for (auto &edge : graph[node]) {
            int w = edge.first;
            int nxt = edge.second;

            if (time + w < dist[nxt]) {
                dist[nxt] = time + w;
                pq.push({dist[nxt], nxt});
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == numeric_limits<int>::max()) {
            cout << -1;
            return 0;  // unreachable node exists
        }
        answer = max(answer, dist[i]);
    }

    cout << answer;
    return 0;
}
