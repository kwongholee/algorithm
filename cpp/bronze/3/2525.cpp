#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int h = c / 60, m = c % 60;
	if (b + m < 60) {
		if (a + h < 24) cout << a + h << " " << b + m;
		else cout << a + h - 24 << " " << b + m;
	}
	else {
		if (a + h < 23) cout << a + h + 1 << " " << b + m - 60;
		else cout << a + h - 23 << " " << b + m - 60;
	}
}