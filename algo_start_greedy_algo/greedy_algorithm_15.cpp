// здесь главное что d это максимум на который может прыгнуть лягушка 
// его надо выбрать но это не обязательно означает что она будет прыгать с шагом d 
// она может прыгнуть и с меньшим шагом но главное чтобы не больше d 
// идея 
//лягушка застревает только на блоках подряд идущих L
// чтобы перепрыгнуть блок длиной k, нужно уметь прыгать хотя бы на k+1
// значит, минимальное d = (максимальная длина блока L) + 1.
#include <iostream>
#include <string>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    std::vector<int> answer;
    answer.reserve(t);
    while (t--) {
        std::string s;
        std::cin >> s;
        int maxlen = 0;   // максимальная длина блока L
        int current = 0;  // текущая длина подряд идущих L
        for (char c : s) {
            if (c == 'L') {
                current++;
                if (current > maxlen) {
                    maxlen = current;
                }
            }
            else {
                current = 0; // сброс при встрече R
            }
        }
        answer.push_back(maxlen + 1);
    }
    for (int a : answer) {
        std::cout << a << "\n";
    }
    return 0;
}
