#include <iostream>
#include <vector>
using namespace std;

void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited,
         int m, int n) {
    visited[x][y] = true;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
            grid[nx][ny] == 1 && !visited[nx][ny]) {
            dfs(nx, ny, grid, visited, m, n);
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int islands = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                islands++;
                dfs(i, j, grid, visited, m, n);
            }
        }
    }

    cout << islands;
    return 0;
}
