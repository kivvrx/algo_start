#include <iostream>
#include <set>

void input(int siz, std::set<int>& ss) {
    for (int i = 0; i < siz; ++i) {
        int k;
        std::cin >> k;
        ss.insert(k);
    }
}

int main() {
    int n, m, q;
    std::cin >> n >> m >> q;
    std::set<int> s;
    input(n, s);
    input(m, s);
    input(q, s);
    std::cout << s.size();
    return 0;
}
