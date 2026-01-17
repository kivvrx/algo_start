#include <iostream>
#include <vector>

int main() {

    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    if (n == 1) {
        std::cout << a[0];
        return 0;
    }

    int best_start = 0, best_len = 1;
    int cur_start = 0, cur_len = 1;
    int dir = 0; // 0 = неизвестно, 1 = возрастание, -1 = убывание

    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            if (dir == 1 || dir == 0) {
                cur_len++;
                dir = 1;
            }
            else {
                if (cur_len > best_len) {
                    best_len = cur_len;
                    best_start = cur_start;
                }
                cur_start = i - 1;
                cur_len = 2;
                dir = 1;
            }
        }
        else if (a[i] < a[i - 1]) {
            if (dir == -1 || dir == 0) {
                cur_len++;
                dir = -1;
            }
            else {
                if (cur_len > best_len) {
                    best_len = cur_len;
                    best_start = cur_start;
                }
                cur_start = i - 1;
                cur_len = 2;
                dir = -1;
            }
        }
        else {
            // равные элементы сброс
            if (cur_len > best_len) {
                best_len = cur_len;
                best_start = cur_start;
            }
            cur_start = i;
            cur_len = 1;
            dir = 0;
        }
    }

    if (cur_len > best_len) {
        best_len = cur_len;
        best_start = cur_start;
    }

    for (int i = best_start; i < best_start + best_len; i++) {
        std::cout << a[i] << ' ';
    }
    std::cout << "\n";

    return 0;
}

