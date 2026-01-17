#include <iostream>

int main() {
    int n;
    long long x;
    std::cin >> n >> x;
    long long ice = x;
    long long sad = 0;
    for (int i = 0; i < n; ++i) {
        char type;
        long long d;
        std::cin >> type >> d;
        if (type == '+') {
            ice += d;
        }
        else { // type == '-'
            if (ice >= d) {
                ice -= d;
            }
            else {
                ++sad;
            }
        }
    }
    std::cout << ice << " " << sad << "\n";
    return 0;
}
