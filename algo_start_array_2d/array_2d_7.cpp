#include <iostream>
#include <vector>
#include <map>
int sum_digits(int x) {
    int s = 0;
    while (x > 0) {
        s += x % 10;
        x /= 10;
    }
    return s;
}
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            std::cin >> matrix[i][j];
    std::map<int, int> row_sum;

    for (int i = 0; i < n; ++i) {
        int total = 0;
        for (int j = 0; j < m; ++j) {
            total += sum_digits(matrix[i][j]);
        }
        row_sum[i] = total;
    }
    int best_row = 0;
    int min_sum = row_sum[0];
    for (auto& p : row_sum) {
        int idx = p.first;
        int val = p.second;
        if (val < min_sum || (val == min_sum && idx > best_row)) {
            min_sum = val;
            best_row = idx;
        }
    }
    for (int j = 0; j < m; ++j) {
        std::cout << matrix[best_row][j] << (j + 1 == m ? '\n' : ' ');
    }
}