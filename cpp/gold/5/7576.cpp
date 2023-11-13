#include <bits/stdc++.h>

using namespace std;

int M, N, cnt = 0, change = 0;
int table[1000][1000], push_x[4] = { -1,0,1,0 }, push_y[4] = { 0,-1,0,1 };
queue<pair<int, int>> q;

void bfs(int change) {
	for (int i = 0; i < change; i++) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int new_x = x + push_x[k], new_y = y + push_y[k];
			if (0 <= new_x and new_x < N and 0 <= new_y and new_y < M and table[new_x][new_y] == 0) {
				q.push({ new_x,new_y });
        table[new_x][new_y] = 1;
			}
		}
	}
	if (q.empty()) return;
	else {
		cnt++;
		bfs(q.size());
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> table[i][j];
			if (table[i][j] == 1) {
				q.push({ i,j });
				change++;
			}
		}
	}
	bfs(change);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (table[i][j] == 0) {
				cnt = -1;
				break;
			}
		}
	}
	cout << cnt;
}