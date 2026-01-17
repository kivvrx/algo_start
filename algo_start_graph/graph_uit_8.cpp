#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // для каждой вершины список соседей
    vector<unordered_set<int>> adj(n + 1);
    vector<int> inp;
    int m_2 = 2 * m;
    while (m_2--) {
        int u;
        cin >> u;
        inp.push_back(u);
    }
    vector<char> ch(n + 1);
    for (int i = 1; i <= n; ++i) {
        char chh;
        cin >> chh;
        ch[i] = chh;
    }

    int l = 0;
    int r = 1;
    while (m--) {
        auto u = inp[l];
        auto v = inp[r];
        if (ch[u] != ch[v])
            adj[u].insert(v);
        l += 2;
        r += 2;
    }

    int minn = INT_MAX;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (!adj[i].empty() && adj[i].size() < minn) {
            minn = adj[i].size();
            ans = i;
        }
    }

    if (ans == 0) {
        cout << -1;
    }
    else {
        cout << ch[ans];
    }
}


