#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	vector<int> v;
	for (int i = 0; i < a; i++) {
		int c;
		cin >> c;
		v.push_back(c);
	}
	for (auto e : v) {
		if (b > e) cout << e << " ";
	}
}