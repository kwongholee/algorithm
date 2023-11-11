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
#include <cstring>

using namespace std;

int m, n, t;
int input[300][300];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input[i][j];
		}
	}
	cin >> t;
	for (int k = 0; k < t; k++) {
		int i, j, x, y, cnt = 0;
		cin >> i >> j >> x >> y;
		for (int a = i - 1; a <= x - 1; a++) {
			for (int b = j - 1; b <= y - 1; b++) {
				cnt += input[a][b];
			}
		}
		cout << cnt << '\n';
	}
}