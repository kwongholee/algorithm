#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a;
	cin >> a;
	vector<int> v(26, -1), v1;
	for (int i = 0; i < a.length(); i++) v1.push_back(a[i]);
	for (int i = 0; i < a.length(); i++) {
		if (v[v1[i] - 97] == -1) v[v1[i] - 97] = i;
	}
	for (auto e : v) cout << e << " ";
}