#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <set>

using namespace std;

int t, n, k;

int func(int n, int k) {
	if (n == 0) return k;
	if (k == 1) return 1;
	else return func((n - 1), k) + func(n, (k - 1));
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> k;
		cout << func(n, k) << '\n';
	}
}