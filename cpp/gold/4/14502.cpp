#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, value = 0, n = 0;
int table[8][8];
int push_x[4] = { -1,0,1,0 }, push_y[4] = { 0,-1,0,1 };
vector<pair<int, int>> virus, notWall;

void bfs(int i, int j, int k) {
	int cnt = n - 3;
	queue<pair<int, int>> q;
	bool visited[8][8] = { false };
	int ix = notWall[i].first, iy = notWall[i].second, jx = notWall[j].first, jy = notWall[j].second, kx = notWall[k].first, ky = notWall[k].second;
	visited[ix][iy] = true;
	visited[jx][jy] = true;
	visited[kx][ky] = true;
	for (auto e : virus) q.push({ e });
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int h = 0; h < 4; h++) {
			int nx = x + push_x[h], ny = y + push_y[h];
			if (!visited[nx][ny] and nx >= 0 and nx < N and ny >= 0 and ny < M and table[nx][ny] == 0) {
				visited[nx][ny] = true;
				cnt--;
				q.push({ nx, ny });
			}
		}
	}
	if (value < cnt) value = cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int a;
			cin >> a;
			table[i][j] = a;
			if (a == 0) {
				notWall.push_back({ i,j });
				n++;
			}
			else if (a == 2) virus.push_back({ i,j });
		}
	}
	for (int i = 0; i < notWall.size(); i++) {
		for (int j = i + 1; j < notWall.size(); j++) {
			for (int k = j + 1; k < notWall.size(); k++) bfs(i, j, k);
		}
	}
	cout << value;
}