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

int T, N, M, K, table[50][50], push_x[4] = {0,1,0,-1}, push_y[4] = {-1,0,1,0};

// void dfs(int a, int b) {
// 	stack<pair<int, int>> s;
// 	s.push({ a,b });
// 	while (!s.empty()) {
// 		int x = s.top().first, y = s.top().second, result = 0;
// 		for (int i = 0; i < 4; i++) {
// 			int new_x = x + push_x[i], new_y = y + push_y[i];
// 			if ((new_x >= 0 and new_x < N) and (new_y >= 0 and new_y < M) and table[new_x][new_y] == 1) {
// 				result = 1;
// 				s.push({ new_x, new_y });
// 				table[new_x][new_y] = 0;
// 				break;
// 			}
// 		}
// 		if (!result) s.pop();
// 	}
// }

void dfs(int a, int b) {
	if(a < 0 or a >= 50 or b < 0 or b >= 50 or table[a][b] == 0) return;
	table[a][b] = 0;
	for(int i = 0; i < 4; i++) {
		dfs(a + push_x[i], b + push_y[i]);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		int cnt = 0;
		vector<pair<int, int>> v;
		for (int j = 0; j < K; j++) {
			int a, b;
			cin >> a >> b;
			table[b][a] = 1;
			v.push_back({ b,a });
		}
		for (auto e : v) {
			if (table[e.first][e.second] == 1) {
				cnt++;
				dfs(e.first, e.second);
			}
		}
		cout << cnt << '\n';
	}
}