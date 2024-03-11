#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, T = 0, cnt = 0;
int table[300][300], copyTable[300][300], dx[] = { -1,0,1,0 }, dy[] = { 0,-1,0,1 };
bool visited[300][300];

void melt(int x, int y) {
	int n = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (0 <= nx and nx < N and 0 <= ny and ny < M and table[nx][ny] == 0) n++;
	}
	if (table[x][y] - n >= 0) copyTable[x][y] =  table[x][y] - n;
	else copyTable[x][y] = 0;
}

void check(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (0 <= nx and nx < N and 0 <= ny and ny < M and !visited[nx][ny] and table[nx][ny] != 0) {
			check(nx, ny);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> table[i][j];
	}
	while (true) {
		T++;
		memset(visited, false, sizeof(visited));
		memset(copyTable, 0, sizeof(copyTable));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (table[i][j] != 0) melt(i, j);
			}
		}
		copy(&copyTable[0][0], &copyTable[0][0] + 90000, &table[0][0]);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (table[i][j] != 0 and !visited[i][j]) {
					if (cnt == 0) check(i, j);
					cnt++;
				}
			}
		}
		if (cnt == 1) cnt = 0;
		else {
			if (cnt == 0) T = 0;
			break;
		}
	}
	cout << T;
}
