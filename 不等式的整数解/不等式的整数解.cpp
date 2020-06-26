#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
#define MAX 0xffff
int main() {
	cout << "求解 5x1 + 4x2 - x3 <= 10" << endl;
	int x1 = 1, x2 = 1, x3 = 0;
	vector<int> vec_x1, vec_x2, vec_x3;
	while (x1 >= 1 && x1 <= 3) {
		if (5 * x1 + 4 * x2 > 13) {
			++x1;
			x2 = 1;
		}
		else {
			if (5 * x1 + 4 * x2 + x3 > 13) {
				++x2;
				if (x2 > 3) {
					++x1;
					x2 = 1;
				}
				x3 = 0;
			}
			else {
				vec_x1.push_back(x1);
				vec_x2.push_back(x2);
				vec_x3.push_back(x3);
				++x3;
				if (x3 > 2) {
					++x2;
					x3 = 0;
					if (x2 > 3) {
						++x1;
						x2 = 1;
					}
				}
			}
		}
	}
	vector<int>::iterator i_x1 = vec_x1.begin(), i_x2 = vec_x2.begin(), i_x3 = vec_x3.begin();
	cout << "整数解有" << endl;
	while (i_x1 != vec_x1.end()) {
		cout << "x1 = " << *i_x1 << "   x2 = " << *i_x2 << "   x3 = " << 3 - *i_x3 << endl;
		i_x1++;
		i_x2++;
		i_x3++;
	}

	return 0;
}