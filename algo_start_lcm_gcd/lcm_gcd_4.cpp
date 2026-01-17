#include <iostream>
#include <vector>
int gcd_itarate(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    long long count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (gcd_itarate(a[i], a[j]) == 1) {
                count++;
            }
        }
    }
    std::cout << count;
    return 0;
}
