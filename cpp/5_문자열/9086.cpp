#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a;
	cin >> a;
	for (int i = 0; i < a; i++) {
		string b;
		cin >> b;
		cout << b[0] << b[b.length() - 1] << '\n';
	}
}