#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;

    for (int nbr : graph[node]) {
        if (!visited[nbr])
            dfs(nbr, graph, visited);
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V);
    vector<bool> visited(V, false);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int components = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            components++;
            dfs(i, graph, visited);
        }
    }

    cout << components;
    return 0;
}
