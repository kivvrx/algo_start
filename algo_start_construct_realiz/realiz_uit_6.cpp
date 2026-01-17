#include <iostream>
#include <vector>

 int f(int cur) {
    if (cur == 0) return 0;
    if (cur % 2 == 1) return (cur + 1) / 2; // нечётное cur
    return cur / 2 + 1;                   // чётное cur > 0
}

int main() {
    int t;
    std::cin >> t;
    std::vector<long long> answers;
    answers.reserve(t);

    while (t--) {
        int n;
        std::cin >> n;
        int cur = 0;           // известные по полу свинки после последнего врача
        int nxt = 0;           // неизвестные свинки с последнего врача
        int ans = 0;         // максимум клеток на любом дне

        for (int i = 0; i < n; ++i) {
            int b;
            std::cin >> b;
            if (b == 1) {
                nxt += 1;
                int now = f(cur) + nxt;
                if (now > ans) ans = now;
            }
            else { // b == 2
                cur += nxt;
                nxt = 0;
                int now = f(cur) + nxt;
                if (now > ans) ans = now;
            }
        }

        answers.push_back(ans);
    }
    for (const auto& x : answers) {
        std::cout << x << '\n';
    }
    return 0;
}
