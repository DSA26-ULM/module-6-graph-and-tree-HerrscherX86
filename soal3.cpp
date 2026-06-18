#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c;
    cin >> r >> c;

    vector<vector<int>> grid(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }

    int sr, sc, fr, fc;
    cin >> sr >> sc;
    cin >> fr >> fc;

    // BFS
    vector<vector<int>> dist(r, vector<int>(c, -1));
    queue<pair<int, int>> q;

    dist[sr][sc] = 0;
    q.push({sr, sc});

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [cr, cc] = q.front(); q.pop();

        if (cr == fr && cc == fc) break;

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr >= 0 && nr < r && nc >= 0 && nc < c 
                && grid[nr][nc] == 0 && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[cr][cc] + 1;
                q.push({nr, nc});
            }
        }
    }

    cout << dist[fr][fc] << "\n";

    return 0;
}
