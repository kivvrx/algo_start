#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> adj(n + 1, vector<bool>(n + 1, false));
    for (int k = 0; k < m; ++k) {
        int u, v;
        cin >> u >> v;
        // дорога в свое же государство по условию не бывает но проверим
        if (u != v) adj[u][v] = true;
    }
    vector<char> label(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> label[i];
    }
    int best = 0;
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            if (adj[i][j] && label[j] == label[i]) {
                ++cnt;
            }
        }
        if (cnt > best) best = cnt;
    }
    cout << best;
    return 0;
}
