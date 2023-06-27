#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a == b and a == c) cout << 10000 + a * 1000;
	else if (a == b or a == c) cout << 1000 + a * 100;
	else if (b == c) cout << 1000 + b * 100;
	else {
		int max = a;
		if (max < b) max = b;
		if (max < c) max = c;
		cout << max * 100;
	}
}