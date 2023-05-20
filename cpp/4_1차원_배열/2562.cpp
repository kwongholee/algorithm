#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> v;
	int max = 0, idx = 0;
	for (int i = 0; i < 9; i++) {
		int a;
		cin >> a;
		v.push_back(a);
		if (max < a) {
			max = a;
			idx = i + 1;
		}
	}
	cout << max << '\n';
	cout << idx;
}