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
		int t = v[m - 1];
		v[m - 1] = v[n - 1];
		v[n - 1] = t;
	}
	for (auto e : v) cout << e << " ";
}