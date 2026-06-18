#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;

    string labels;
    cin >> labels >> m;

    // Mapping label ke index
    map<char, int> idx;
    for (int i = 0; i < n; i++) {
        idx[labels[i]] = i;
    }

    // Inisialisasi matrix n x n dengan 0
    vector<vector<int>> adj(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        char u, v;
        int w;
        cin >> u >> v >> w;
        adj[idx[u]][idx[v]] = w;
    }

    // Output
    cout << "Adjacency Matrix:\n";
    cout << "  ";
    for (char c : labels) cout << c;
    cout << "\n";

    for (int i = 0; i < n; i++) {
        cout << labels[i] << " ";
        for (int j = 0; j < n; j++) {
            cout << adj[i][j];
        }
        cout << "\n";
    }

    return 0;
}
