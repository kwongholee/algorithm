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

int N, M, start_x, start_y, push_x[4] = { -1,0,1,0 }, push_y[4] = { 0,-1,0,1 };
char table[600][600];
bool visited[600][600] = { false };

void bfs(int a, int b) {
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = true;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int new_x = x + push_x[i], new_y = y + push_y[i];
			if (0 <= new_x and new_x < N and 0 <= new_y and new_y < M and !visited[new_x][new_y] and table[new_x][new_y] != 'X') {
				q.push({ new_x, new_y });
				visited[new_x][new_y] = true;
				if (table[new_x][new_y] == 'P') cnt++;
			}
		}
	}
	if (cnt != 0) cout << cnt;
	else cout << "TT";
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			table[i][j] = s[j];
			if (s[j] == 'I') {
				start_x = i, start_y = j;
			}
		}
	}
	bfs(start_x, start_y);
}