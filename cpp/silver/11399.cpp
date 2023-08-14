#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num, total = 0, result = 0;
	vector<int> v, v2;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	for (auto e : v) {
		total += e;
		v2.push_back(total);
	}
	for (auto e : v2) {
		result += e;
	}
	cout << result;
}