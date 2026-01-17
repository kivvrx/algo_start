// Каждое число от 1 до n встречается в a ровно дважды
// так как было две копии перестановки
// первая встреча числа в a соответствует его появлению в первой копии p
// значит чтобы восстановить p достаточно пройти по a
// слева направо и записывать число только при его первом появлении

#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            std::cin >> a[i];
        }
        std::vector<bool> used(n + 1, false); // числа 1,2,3... n
        std::vector<int> p;
        for (int x : a) {
            if (!used[x]) {
                p.push_back(x);
                used[x] = true;
            }
        }
        for (int i = 0; i < n; i++) {
            std::cout << p[i] << (i + 1 == n ? '\n' : ' ');
        }
    }
    return 0;
}
