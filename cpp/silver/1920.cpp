#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int n, m;
vector<int> vecn;

void binsearch(int a) {
	int start = 0, end = n - 1;
	int mid;
	while (end >= start) {
		mid = (start + end) / 2;
		if (a == vecn[mid]) {
			cout << 1 << '\n';
			return;
		}
		else if (a > vecn[mid]) start = mid + 1;
		else end = mid - 1;
	}
	cout << 0 << '\n';
	return;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		vecn.push_back(a);
	}
	sort(vecn.begin(), vecn.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a;
		binsearch(a);
	}
}