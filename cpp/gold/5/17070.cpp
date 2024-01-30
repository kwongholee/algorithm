#include <iostream>

using namespace std;

int N, n = 0;
bool visited[16][16] = { false };
int table[16][16];
int push_x[3] = { 0,1,1 }, push_y[3] = { 1,0,1 };

void dfs(int x, int y, int dir) {
    if (x == N - 1 and y == N - 1) {
        n++;
        return;
    }
    visited[x][y] = true;
    for (int i = 0; i < 3; i++) {
        if (dir == 0 and i == 1) continue;
        else if (dir == 1 and i == 0) continue;
        else {
            int nx = x + push_x[i];
            int ny = y + push_y[i];
            if (nx < 0 or ny < 0 or nx >= N or ny >= N) continue;
            if (i < 2) {
                if (!table[nx][ny] and !visited[nx][ny]) {
                    dfs(nx, ny, i);
                    visited[nx][ny] = false;
                }
            }
            else { 
                if (!table[nx][ny] and !table[nx - 1][ny] and !table[nx][ny - 1] and !visited[nx][ny]) {
                    dfs(nx, ny, i);
                    visited[nx][ny] = false;
                }
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> table[i][j];
	}
	dfs(0, 1, 0);
	cout << n;
}