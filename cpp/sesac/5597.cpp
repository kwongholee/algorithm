#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> v;
	for (int i = 0; i < 30; i++) v.push_back(i + 1);
	for (int i = 0; i < 28; i++) {
		int a;
		cin >> a;
		v.erase(remove(v.begin(), v.end(), a), v.end());
	}
	for (auto e : v) cout << e << '\n';
}