#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    std::vector<int> answers;
    answers.reserve(t);
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        int height = 1;            // начальная высота
        int zero = 0; // подряд нулей
        bool prev = false; // вчера был полив
        int result = 0;            // итог для набора

        bool ok = false;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                ++zero;
                prev = false;
                if (zero == 2) {
                    ok = true;
                    break; // завял
                }
                // рост не меняется
            }
            else { // a[i] == 1
                zero = 0;
                if (prev) {
                    height += 5;
                }
                else {
                    height += 1;
                }
                prev = true;
            }
        }
        result = ok ? -1 : height;
        answers.push_back(result);
    }
    for (int x : answers) {
        std::cout << x << '\n';
    }
    return 0;
}
