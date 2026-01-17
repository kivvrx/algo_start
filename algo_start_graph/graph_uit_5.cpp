#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> mat(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> mat[i][j];
        }
    }
    int k;
    cin >> k;
    vector<int> a(k + 1);
    for (int i = 1; i <= k; ++i) cin >> a[i];
    long long total = 0;
    bool ok = true;
    for (int i = 1; i < k; ++i) {
        int u = a[i], v = a[i + 1];
        int w = mat[u][v]; // расстояние по направлению u -> v
        if (w == 0) { // дороги нет
            ok = false;
            break;
        }
        total += w;
    }
    cout << total << "\n";
    cout << (ok ? "Done" : "Interrupted") << "\n";
    return 0;
}
