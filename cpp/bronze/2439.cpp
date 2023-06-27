#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a;
	string b = "*";
	cin >> a;
	for (int i = 0; i < a; i++) {
		string c = "";
		for (int j = 0; j < a - i-1; j++) c += " ";
		cout << c << b << '\n';
		b += "*";
	}
}