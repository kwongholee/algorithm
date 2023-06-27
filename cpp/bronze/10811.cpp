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
	for (int i = 0; i < a; i++) v.push_back(i + 1);
	for (int i = 0; i < b; i++) {
		int m, n;
		cin >> m >> n;
		vector<int> v1(m);
		if (a == b) continue;
		else {
			for (int j = a - 1; j < b; j++) v1[j] = v[b + a - 2 - j];
			for (int j = a - 1; j < b; j++) v[j] = v1[j];
		}
	}
	for (auto e : v) cout << e << " ";
}