// чтобы не учитывать дважды считаем только если u<v
#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges.insert({ u, v });
    }
    int count = 0;
    for (auto [u, v] : edges) {
        if (edges.count({ v, u }) && u < v) {
            ++count;
        }
    }
    cout << count << "\n";
    return 0;
}
