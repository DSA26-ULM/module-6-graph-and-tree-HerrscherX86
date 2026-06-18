#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // Baca N label vertex (bisa dengan atau tanpa spasi)
    vector<char> labels;
    string token;

    while ((int)labels.size() < n && cin >> token) {
        for (char c : token) {
            if (labels.size() < n) {
                labels.push_back(c);
            }
        }
    }

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Adjacency List:\n";
    for (int i = 0; i < n; i++) {
        cout << labels[i] << "->";
        bool first = true;
        bool hasEdge = false;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > 0) {
                if (!first) cout << ",";
                cout << "(" << labels[j] << "," << matrix[i][j] << ")";
                first = false;
                hasEdge = true;
            }
        }
        if (!hasEdge) cout << "-";
        cout << "\n";
    }

    return 0;
}
