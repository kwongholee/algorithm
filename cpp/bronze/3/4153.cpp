#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0 and b == 0 and c == 0) break;
		else {
			if (a > b and a > c) {
				if (a * a == b * b + c * c) cout << "right" << '\n';
				else cout << "wrong" << '\n';
			}
			else if (b > a and b > c) {
				if (b * b == a * a + c * c) cout << "right" << '\n';
				else cout << "wrong" << '\n';
			}
			else {
				if (c * c == b * b + a * a) cout << "right" << '\n';
				else cout << "wrong" << '\n';
			}
		}
	}
}