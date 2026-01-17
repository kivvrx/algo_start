#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> adj(n + 1, vector<bool>(n + 1, false));
    for (int t = 0; t < m; ++t) {
        int u, v;
        cin >> u >> v;
        if (u != v) adj[u][v] = true; // по условию петель нет
    }
    set<tuple<int, int, int>> three;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j == i) continue;
            for (int k = 1; k <= n; ++k) {
                if (k == i || k == j) continue;
                if (adj[i][j] && adj[j][k] && adj[k][i]) {
                    // приводим к формату вывода отсортировать вершины по возрастанию
                    int a = i, b = j, c = k;
                    if (a > b) swap(a, b);
                    if (b > c) swap(b, c);
                    if (a > b) swap(a, b);
                    three.insert({ a, b, c });
                }
            }
        }
    }
    if (three.empty()) {
        cout << -1;
    }
    else {
        for (auto [a, b, c] : three) {
            cout << a << " " << b << " " << c << "\n";
        }
    }
    return 0;
}
