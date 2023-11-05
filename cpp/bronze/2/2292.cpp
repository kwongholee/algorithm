#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num;
	cin >> num;
	if (num == 1) cout << num;
	else {
		int i = 1;
		num -= 1;
		while (true) {
			if (num - 6 * i <= 0) break;
			else {
				num -= 6 * i;
				i++;
			}
		}
		cout << i+1;
	}
}