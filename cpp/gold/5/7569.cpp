#include <bits/stdc++.h>

using namespace std;

int M, N, H, cnt = 0, change = 0;
int table[100][100][100], push_x[6] = { -1,0,1,0,0,0 }, push_y[6] = { 0,-1,0,1,0,0 }, push_z[6] = { 0,0,0,0,1,-1 };
queue<pair<int,pair<int, int>>> q;

void bfs(int change) {
	for (int i = 0; i < change; i++) {
		int z = q.front().first, x = q.front().second.first, y = q.front().second.second;
		q.pop();
		for (int k = 0; k < 6; k++) {
			int new_x = x + push_x[k], new_y = y + push_y[k], new_z = z + push_z[k];
			if (0 <= new_x and new_x < N and 0 <= new_y and new_y < M and 0 <= new_z and new_z < H and table[new_z][new_x][new_y] == 0) {
				q.push({ new_z,{ new_x,new_y } });
        table[new_z][new_x][new_y] = 1;
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

	cin >> M >> N >> H;
	for(int k = 0; k < H; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cin >> table[k][i][j];
        if (table[k][i][j] == 1) {
          q.push({k,{ i,j }});
          change++;
        }
      }
    }
  }
	bfs(change);
	for(int k = 0; k < H; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (table[k][i][j] == 0) {
          cnt = -1;
          break;
        }
      }
    }
  }
	cout << cnt;
}