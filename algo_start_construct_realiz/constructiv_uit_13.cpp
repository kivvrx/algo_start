#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    std::vector<std::vector<int>> results;
    results.reserve(t);

    while (t--) {
        int n, a, b;
        std::cin >> n >> a >> b;
        // формула n - a +1 очевидна если представить массив перестановку
        int leftcand = (n - a + 1) - (b >= a ? 1 : 0);

        int rightcand = b - (a <= b ? 1 : 0);
        if (leftcand < n / 2 || rightcand < n / 2) {
            results.push_back({ -1 });
            continue;
        }
        std::vector<int> left, right;

        // левая половина a + самые большие числа >= a кроме b
        left.push_back(a);
        for (int x = n; x >= 1 && (int)left.size() < n / 2; --x) {
            if (x == a || x == b) continue;
            if (x >= a) left.push_back(x);
        }
        // правая половина b + самые маленькие числа <= b кроме a
        right.push_back(b);
        for (int x = 1; x <= n && (int)right.size() < n / 2; ++x) {
            if (x == a || x == b) continue;
            if (x <= b) right.push_back(x);
        }
        std::vector<int> perm;
        perm.reserve(n);
        perm.insert(perm.end(), left.begin(), left.end());
        perm.insert(perm.end(), right.begin(), right.end());
        results.push_back(std::move(perm));
    }

    for (const auto& perm : results) {
        if (perm.size() == 1 && perm[0] == -1) {
            std::cout << -1 << '\n';
        }
        else {
            for (std::size_t i = 0; i < perm.size(); ++i) {
                std::cout << perm[i] << (i + 1 == perm.size() ? '\n' : ' ');
            }
        }
    }

    return 0;
}
