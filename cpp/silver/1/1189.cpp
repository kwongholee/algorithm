#include <iostream>

using namespace std;

int R, C, K, cnt = 0;
int dx[] = { -1,0,1,0 }, dy[] = { 0,-1,0,1 };
bool map[5][5], visited[5][5] = { false };

void dfs(int r, int c, int n) {
	visited[r][c] = true;
	if (r == 0 and c == C - 1 and n == K) cnt++;
	for (int i = 0; i < 4; i++) {
		int nr = r + dx[i], nc = c + dy[i];
		if (!visited[nr][nc] and 0 <= nr and nr < R and 0 <= nc and nc < C and !map[nr][nc]) dfs(nr, nc, n + 1);
	}
	visited[r][c] = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C >> K;
	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < C; j++) {
			if (s[j] == 'T') map[i][j] = true;
		}
	}
	dfs(R - 1, 0, 1);
	cout << cnt;
}