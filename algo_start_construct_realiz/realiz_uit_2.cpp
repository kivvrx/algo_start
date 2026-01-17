#include <iostream>
#include <string>
using namespace std;
const char S = '7';
const char F = '4';
int main() {
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    while (n--) {
        int i;
        int count = 0;
        cin >> i;
        string s = to_string(i);
        for (auto ss : s) {
            if (ss == F || ss == S) count += 1;
        }
        cnt += (count <= k ? 1 : 0);
    }
    cout << cnt;
    return 0;
}
