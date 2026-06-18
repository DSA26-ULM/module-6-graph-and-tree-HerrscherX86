#include <bits/stdc++.h>
using namespace std;

int r, c, sr, sc, fr, fc;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int pathCount = 0;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dfs(int cr, int cc) {
    if (cr == fr && cc == fc) {
        pathCount++;
        return;
    }

    visited[cr][cc] = true;

    for (int i = 0; i < 4; i++) {
        int nr = cr + dr[i];
        int nc = cc + dc[i];

        if (nr >= 0 && nr < r && nc >= 0 && nc < c 
            && grid[nr][nc] == 0 && !visited[nr][nc]) {
            dfs(nr, nc);
        }
    }

    visited[cr][cc] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;

    grid.resize(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> sr >> sc;
    cin >> fr >> fc;

    visited.resize(r, vector<bool>(c, false));
    dfs(sr, sc);

    cout << pathCount << "\n";

    return 0;
}
