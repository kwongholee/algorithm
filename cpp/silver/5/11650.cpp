#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num, x, y;
	cin >> num;
	vector<vector<int>> v;
	for (int i = 0; i < num; i++) {
		cin >> x >> y;
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end());
	for (auto e : v) {
		cout << e[0] << ' ' << e[1] << '\n';
	}
}