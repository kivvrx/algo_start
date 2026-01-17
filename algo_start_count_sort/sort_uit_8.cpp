#include <iostream>
#include <vector>

bool powtwo(int x) {
    return x == 1 || x == 2 || x == 4 || x == 8 || x == 16;
}

int main() {
    int t;
    std::cin >> t;
    std::vector<std::string> results;
    results.reserve(t);
    for (int _ = 0; _ < t; ++_) {
        int n;
        std::cin >> n;
        std::vector<int> a(n+1);
        for (int i = 1; i < n + 1; ++i) {
            std::cin >> a[i];
        }
        bool ok = true;
        // 0 6 4 6 2 4 мы не сможем уменьшить 3 - й элемент 
        // не уменьшая четвертый а значит ничего не изменится решения нет
        for (int i = 1; i <= n - 1; ++i) { // i 1 позиция
            if (!powtwo(i)) {
                if (a[i] > a[i + 1]) {
                    ok = false;
                    break;
                }
            }
        }
        results.push_back(ok ? "YES" : "NO");
    }
    for (const auto& ans : results) {
        std::cout << ans << "\n";
    }
    return 0;
}
//8
//5
//1 2 3 4 5
//5
//6 5 3 4 4
//9
//6 5 5 7 5 6 6 8 7
//4
//4 3 2 1
//6
//2 2 4 5 3 2
//8
//1 3 17 19 27 57 179 13
//5
//3 17 57 179 92
//10
//1 2 3 4 0 6 7 8 9 10
