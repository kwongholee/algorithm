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

int N;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	vector<int> table(N + 1);
	table[1] = 0;
	for (int i = 2; i <= N; i++) {
		table[i] = table[i - 1] + 1;
		if (i % 3 == 0) table[i] = min(table[i], table[i / 3] + 1);
		if (i % 2 == 0) table[i] = min(table[i], table[i / 2] + 1);
	}
	cout << table[N];
}