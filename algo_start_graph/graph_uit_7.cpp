#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matr(n, vector<int>(n, 0));
    while (m--) {
        int u, v;
        cin >> u >> v;
        matr[u - 1][v - 1] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
