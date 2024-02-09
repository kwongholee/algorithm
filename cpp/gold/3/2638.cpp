#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M, t = 0;
int table[100][100], visited[100][100], air[100][100];
int dx[] = { -1,0,1,0 }, dy[] = { 0,-1,0,1 };
queue<pair<int, int>> q;

void cheese() {
	queue<pair<int,int>> q;
	q.push({ 0,0 });
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		if (visited[x][y]) continue;
		visited[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 or nx >= N or ny < 0 or ny >= M) continue;
			if (table[nx][ny] == 1) air[nx][ny]++;
			else if (!visited[nx][ny]) q.push({ nx,ny });
		}
	}
}

bool melt() {
	bool isMelted = false;
	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < M - 1; j++) {
			if (air[i][j] >= 2) {
				table[i][j] = 0;
				isMelted = true;
			}
		}
	}
	return isMelted;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> table[i][j];
	}
	while (true) {
		memset(visited, 0, sizeof(visited));
		memset(air, 0, sizeof(air));
		cheese();
		bool isMelt = melt();
		if (isMelt) t++;
		else break;
	}
	cout << t;
}