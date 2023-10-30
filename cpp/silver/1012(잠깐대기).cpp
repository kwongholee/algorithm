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

int T, N, M, K, table[50][50];

void dfs(int a, int b) {
	stack<pair<int, int>> s;
	s.push({ a,b });
	while (!s.empty()) {
		int x = s.top().first, y = s.top().second;
		table[x][y] = 0;
		if (x == M - 1 and y == N - 1) {
			if (table[x][y - 1] == 1) s.push({ x,y - 1 });
			else s.pop();
		}
		else if (x == M - 1) {
			if (table[x][y - 1] == 1) s.push({ x,y - 1 });
			else if (table[x][y + 1] == 1) s.push({ x,y + 1 });
			else s.pop();
		}
		else if (y == 0) {
			if (table[x + 1][y] == 1) s.push({ x + 1,y });
			else if (table[x][y + 1] == 1) s.push({ x,y + 1 });
			else s.pop();
		}
		else if (y == N - 1) {
			if (table[x][y - 1] == 1) s.push({ x,y - 1 });
			else if (table[x + 1][y] == 1) s.push({ x + 1,y });
			else s.pop();
		}
		else {
			if (table[x][y - 1] == 1) s.push({ x,y - 1 });
			else if (table[x + 1][y] == 1) s.push({ x + 1,y });
			else if (table[x][y + 1] == 1) s.push({ x,y + 1 });
			else s.pop();
		}
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
			table[a][b] = 1;
			v.push_back({ a,b });
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