#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<pair<int, int>> v;
    while (t--) {
        int num;
        cin >> num;
        string s = to_string(num);
        if (s.size() < 2) {
            cout << -1 << endl;
            continue; 
        }
        bool found = false;

        for (int i = 1; i < s.size(); ++i) {

            if (s[i] != '0') { 
                int a = stoi(s.substr(0, i));
                int b = stoi(s.substr(i)); 
                if (b > a && a > 0 && b > 0) {
                    v.emplace_back(a, b);
                    found = true;
                    break;
                }
            }
        }
        if (!found) {
            v.emplace_back(-1, -1);
        }
    }
    for (const auto& vv : v) {
        if (vv.first == -1) cout << -1 << '\n';
        else cout << vv.first << ' ' << vv.second << '\n';
    }
    return 0;
}