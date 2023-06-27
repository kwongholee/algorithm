#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		for (int j = a - 1; j < b; j++) {
			v[j] = c;
		}
	}
	for (auto e : v) {
		cout << e << " ";
	}
}