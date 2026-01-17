#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 1; i < n; ++i) {
        int v_i;
        cin >> v_i; 
        v[i] = v_i;
        // тоесть i элемент не обязательно от 1 до 2 он первый в смысле 
        // того интервала с шагом 1 на интервале от a До b s
    }
    int a, b;
    cin >> a >> b;
    int sum = 0;
    for (int i = a; i < b; ++i) {
        sum += v[i];
    }
    cout << sum;
    return 0;
}
