#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a;
	cin >> a;
	vector<int> v;
	for (int i = 0; i < a; i++) {
		int b;
		cin >> b;
		v.push_back(b);
	}
	int max = v[0], min = v[0];
	for (auto e : v) {
		if (max < e) max = e;
		if (min > e) min = e;
	}
	cout << min << " " << max;
}