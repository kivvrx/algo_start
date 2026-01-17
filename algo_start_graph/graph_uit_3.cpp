// если оба направления ненулевые и разные считаются две односторонние 
// дороги i->j и j->i
// если одно направление ноль а другое не ноль считается одна односторонняя дорога 
// это существующее направление
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> mat(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> mat[i][j];

    int two = 0;
    int one = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int a = mat[i][j];
            int b = mat[j][i];
            if (a == b && a != 0) {
                ++two;
            } else if (a != b) {
                // считаем по направлению каждое ненулевое направление при неравных 
                // длинах это односторонняя дорога
                if (a > 0) ++one;
                if (b > 0) ++one;
            }
            // если a == b == 0 дорог нет ничего не прибавляем
        }
    }

    cout << two << " " << one;
    return 0;
}


