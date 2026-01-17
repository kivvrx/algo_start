#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> moves_count(t);
    vector<vector<int>> steps(t);
    for (int i = 0; i < t; i++) {
        int x, k;
        cin >> x >> k;

        if (x % k != 0) {
            moves_count[i] = 1;
            steps[i] = { x };
        }
        else {
            moves_count[i] = 2;
            if ((x - 1) % k != 0) {
                steps[i] = { 1, x - 1 };
            }
            else {
                steps[i] = { 2, x - 2 };
            }
        }
    }
    for (int i = 0; i < t; i++) {
        cout << moves_count[i] << endl;
        for (int j = 0; j < steps[i].size(); j++) {
            cout << steps[i][j];
            if (j < steps[i].size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}