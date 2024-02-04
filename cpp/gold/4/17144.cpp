#include <iostream>

using namespace std;

int R, C, T, x, y;
int dustFilter = 0, total = 0;
int table[50][50], copyTable[50][50], dx[] = { -1,0,1,0 }, dy[] = { 0,-1,0,1 };

void dust(int a, int b) {
	int n = table[a][b], cnt = 0;
	if (table[a][b] < 5) {
		copyTable[a][b] += n;
		return;
	}
	for(int i = 0; i < 4; i++) {
		int nx = a + dx[i], ny = b + dy[i];
		if (0 <= nx and nx < R and 0 <= ny and ny < C and table[nx][ny] != -1) {
			copyTable[nx][ny] += n / 5;
			cnt++;
		}
	}
	copyTable[a][b] += n - n / 5 * cnt;
}

void cleaner(int a, int b, bool up) {
	if (up) {
		if (a == x - 1 and b + 1 < C) {
			swap(dustFilter, table[a][b + 1]);
			cleaner(a, b + 1, up);
		}
		else if (b == C - 1 and a - 1 >= 0) {
			swap(dustFilter, table[a - 1][b]);
			cleaner(a - 1, b, up);
		}
		else if (a == 0 and b - 1 >= 0) {
			swap(dustFilter, table[a][b - 1]);
			cleaner(a, b - 1, up);
		}
		else if (b == 0 and a + 1 < x - 1) {
			swap(dustFilter, table[a + 1][b]);
			cleaner(a + 1, b, up);
		}
	}
	else {
		if (a == x and b + 1 < C) {
			swap(dustFilter, table[a][b + 1]);
			cleaner(a, b + 1, up);
		}
		else if (b == C - 1 and a + 1 < R) {
			swap(dustFilter, table[a + 1][b]);
			cleaner(a + 1, b, up);
		}
		else if (a == R - 1 and b - 1 >= 0) {
			swap(dustFilter, table[a][b - 1]);
			cleaner(a, b - 1, up);
		}
		else if (b == 0 and a - 1 > x) {
			swap(dustFilter, table[a - 1][b]);
			cleaner(a - 1, b, up);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int a;
			cin >> a;
			table[i][j] = a;
			if (a == -1) x = i, y = j;
		}
	}
	while (T--) {
		fill_n(&copyTable[0][0], 50 * 50, 0);
		copyTable[x][y] = -1;
		copyTable[x - 1][y] = -1;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if(table[i][j] > 0) dust(i, j);
			}
		}
		copy(&copyTable[0][0], &copyTable[0][0] + 2500, &table[0][0]);
		dustFilter = 0;
		cleaner(x - 1, y, true);
		dustFilter = 0;
		cleaner(x, y, false);
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (table[i][j] > 0) total += table[i][j];
		}
	}
	cout << total;
}