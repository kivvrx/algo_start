#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> a(N, std::vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            std::cin >> a[i][j];
    long long sumUpper = 0, sumLower = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j > i) sumUpper += a[i][j];
            else if (i > j) sumLower += a[i][j];
        }
    }
    if (sumUpper > sumLower)
        std::cout << "lower\n";
    else if (sumLower > sumUpper)
        std::cout << "upper\n";
    else
        std::cout << "draw\n";

    return 0;
}