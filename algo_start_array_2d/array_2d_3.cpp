#include <iostream>
#include <vector>
#include <map>

int main() {
    int n, m;
    std::cin >> n >> m;
        
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            std::cin >> matrix[i][j];
    int q;
    std::cin >> q;
    std::map<int, bool> row_type;
    for (int i = 0; i < q; ++i) {
        int row;
        std::cin >> row;
        row_type[row - 1] = true; // отмечаем строка чётная
    }
    int even_count = 0;
    int odd_count = 0;
    for (int i = 0; i < n; ++i) {
        for (int val : matrix[i]) {
            if (row_type[i]) { // если строка в r
                if (val % 2 == 0) ++even_count;
            }
            else {           // если строки нет в r
                if (val % 2 != 0) ++odd_count;
            }
        }
    }
    std::cout << even_count << '\n' << odd_count << '\n';
    return 0;
}