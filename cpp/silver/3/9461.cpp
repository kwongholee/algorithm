#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <set>

using namespace std;

int T;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> T;
	for (int i = 0; i < T; i++) {
		int a;
		cin >> a;
		long long table[101] = { 0,1,1 };
		for (int k = 3; k <= a; k++) {
			table[k] = table[k - 2] + table[k - 3];
		}
		cout << table[a] << '\n';
	}
}