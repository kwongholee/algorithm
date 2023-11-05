#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == 0 and b == 0) break;
		else cout << a + b << endl;
	}
}