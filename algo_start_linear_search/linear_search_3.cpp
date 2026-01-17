//2 2 9 1 2 9 9 9 - 3 - 3 2 2
#include <algorithm>
#include <iostream>
#include <vector>
int main() {
	int n;
	std::cin >> n;
	std::vector<int>a_v (n);
	for (auto& a_i : a_v) {
		std::cin >> a_i;
	}
	auto it_max = max_element(a_v.begin(), a_v.end());
	auto index_max = std::distance(a_v.begin(), it_max);
	auto it_min = min_element(a_v.begin(), a_v.end());
	auto index_min = std::distance(a_v.begin(), it_min);
	if (it_max == it_min) {
		std::cout << -1;
		return 0;
	}
	auto max_val = *it_max;
	auto min_val = *it_min;
	// мы нашли первое вхождение максимума и минима если идти по массиву 
	// от начала до конца
 	// если 123 1 < 555 23 значит надо пройтись пока будут пятерки в задаче дальняя 
	// граница означает 
	// максимально дальняя относительно начала тоесть если есть остров одинаковых 
	// чисел то максимально
	// правое одинаковое значение это означает дальняя граница 
// 123 111 <555 23
	//				  |    |
	// идем   от до в
		while ((it_max+1) != a_v.end() && max_val == *++it_max) {
			++index_max;
		}
	// 123 555 < 111 23
	//				       |    |
	// идем        от до 
		while ((it_min + 1) != a_v.end() && min_val == *++it_min) {
			++index_min;
		}
		// мы идем по обоим островам тоесть на этом этапе мы прошли в правые места в обоих
	// допустим у нас 222 333
	//индексы              012 345
	//значит расстояние это 5-2 и еще -1=2 так как расстояние 2 между 5 и 2 у нас 3 и 4
	std::cout << (index_max > index_min ? index_max - index_min - 1 : index_min - index_max - 1);
 	return 0;
}
