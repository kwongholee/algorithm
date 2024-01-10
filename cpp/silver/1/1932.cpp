#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

int n, max_value = 0;
int table[501][501];
int result[501][501];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) cin >> table[i][j];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) result[i][j] = max(result[i - 1][j - 1] + table[i][j], result[i - 1][j] + table[i][j]);
	}
	for (int i = 1; i <= n; i++) max_value = max(max_value, result[n][i]);
	cout << max_value;
}