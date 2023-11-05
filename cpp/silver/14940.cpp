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

int n, m, start_x, start_y, cnt = 0;
int input[1000][1000], visited[1000][1000];

void bfs(int x, int y, int cnt) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = 1;
	while (!q.empty()) {
		int a = q.front().first, b = q.front().second, push_x[4] = { -1,0,1,0 }, push_y[4] = {0,-1,0,1};
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			int new_x = a + push_x[i], new_y = b + push_y[i];
			if (new_x >= 0 and new_x < n and new_y >= 0 and new_y < m) {
				if (visited[new_x][new_y] == 0 and input[new_x][new_y] != 0) {
					visited[new_x][new_y] = visited[a][b] + 1;
					q.push({ new_x,new_y });
				}
			};
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> input[i][j];
			if (input[i][j] == 2) {
				start_x = i;
				start_y = j;
			}
		}
	}
	bfs(start_x, start_y, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(input[i][j] == 0) cout << 0 << " ";
			else cout << visited[i][j] - 1 << " ";
		}
		cout << '\n';
	}
}