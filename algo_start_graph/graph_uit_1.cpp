// каждая строка если столбец единица выводим индекс + 1 
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> grid[i][j];

    for (int i = 0; i < N; ++i) {
        bool is1 = false;
        for (int j = 0; j < N; ++j) {
            if (grid[i][j] == 1) {
                cout << j + 1 << " ";
                is1 = true;
            }
        }
        if (!is1)
            cout << -1;
        cout << "\n";
    }
    return 0;
}
