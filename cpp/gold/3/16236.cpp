#include <iostream>
#include <queue>

using namespace std;

int N, x, y, t = 0, n = 0, s = 2;
int table[20][20];
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0,-1,0,1 };

void bfs(int a, int b) {
	bool visited[20][20] = { false };
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0, {a,b} });
	table[a][b] = 0;
	visited[a][b] = true;
	int tmpTime = 99999, tmpX = 99999, tmpY = 99999;
	bool flag = false;
	while (!q.empty()) {
		int qt = q.front().first, qx = q.front().second.first, qy = q.front().second.second;
		q.pop();
		if (tmpTime < qt) continue;
		if (table[qx][qy] != 0 and table[qx][qy] < s) {
			flag = true;
			if (tmpX > qx) tmpX = qx, tmpY = qy, tmpTime = qt;
			else if (tmpX == qx) {
				if (tmpY > qy) tmpX = qx, tmpY = qy, tmpTime = qt;
			}
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int nx = qx + dx[i], ny = qy + dy[i];
			if (!visited[nx][ny] and 0 <= nx and nx < N and 0 <= ny and ny < N and table[nx][ny] <= s) {
				q.push({ qt + 1, {nx,ny} });
				visited[nx][ny] = true;
			}
		}
	}
	if (!flag) return;
	else {
		x = tmpX, y = tmpY;
		t += tmpTime;
		n++;
		if (n == s) {
			n = 0;
			s += 1;
		}
		bfs(x, y);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> table[i][j];
			if (table[i][j] == 9) x = i, y = j;
		}
	}
	bfs(x, y);
	cout << t;
}