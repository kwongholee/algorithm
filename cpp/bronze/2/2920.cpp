#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> v;
	bool result1 = true;
	bool result2 = true;
	for (int i = 0; i < 8; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < 7; i++) {
		if (v[i] + 1 != v[i + 1]) {
			result1 = false;
			break;
		}
	}
	for (int i = 0; i < 7; i++) {
		if (v[i] - 1 != v[i + 1]) {
			result2 = false;
			break;
		}
	}
	if (result1) cout << "ascending";
	else if (result2) cout << "descending";
	else cout << "mixed";
}