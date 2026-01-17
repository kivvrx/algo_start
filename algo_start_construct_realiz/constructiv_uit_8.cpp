#include <iostream>
#include <string>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    std::vector<std::string> results;
    results.reserve(t);

    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::string a, b;
        std::cin >> a >> b;

        // 1) проверка суффикса a[n-m+1 .. n-1] соотнести с b[1 .. m-1]
        bool ok = true;
        for (int i = 1; i < m; ++i) {
            if (a[n - m + i] != b[i]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            results.push_back("NO");
            continue;
        }

        // 2) проверка наличия b[0] в префиксе a[0 .. n-m]
        bool has = false;
        for (int i = 0; i <= n - m; ++i) {
            if (a[i] == b[0]) {
                has = true;
                break;
            }
        }
        results.push_back(has ? "YES" : "NO");
    }
    for (const auto& res : results) {
        std::cout << res << '\n';
    }
    return 0;
}
