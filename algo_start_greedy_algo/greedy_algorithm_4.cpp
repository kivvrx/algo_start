// входные массивы это стоимости первый по строкам второй по столбцам
#include <iostream>
#include <vector>
#include <limits>

int main() {
    int t;
    std::cin >> t;
    std::vector<long long> ans;
    while (t--) {
        int n;
        std::cin >> n; // размер доски n строк и n столбцов

        // массивы цен для строк и столбцов
        std::vector<long long> a(n), b(n);

        long long sumA = 0; // сумма всех a[i]
        long long sumB = 0; // сумма всех b[j]
        long long minA = std::numeric_limits<long long>::max(); // минимум в a
        long long minB = std::numeric_limits<long long>::max(); // минимум в b

        // A и B это два варианта как может получится 
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            sumA += a[i];
            if (a[i] < minA) minA = a[i];
        }

        for (int j = 0; j < n; ++j) {
            std::cin >> b[j];
            sumB += b[j];
            if (b[j] < minB) minB = b[j];
        }
        // сценарий 1: покрыть все строки
        // стоимость: каждая строка i требует фишку (a[i]) в самом дешёвом столбце (minB)
        long long cost_rows = sumA + static_cast<long long>(n) * minB;
        // сценарий 2: покрыть все столбцы
        // стоимость: каждый столбец j требует фишку (b[j]) в самой дешёвой строке (minA)
        long long cost_cols = sumB + static_cast<long long>(n) * minA;
        // ответ минимум из двух сценариев
        long long answer = (cost_rows < cost_cols) ? cost_rows : cost_cols;
        ans.push_back(answer);
    }
    for (const auto& aa : ans) std::cout << aa << '\n';
    return 0;
}

