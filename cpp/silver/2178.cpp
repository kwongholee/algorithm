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

int N, M, input[101][101], dist[101][101], x_dir[4] = { -1,1,0,0 }, y_dir[4] = {0,0,-1,1};
bool visited[101][101];
queue<pair<int, int>> q;

void bfs(int a, int b) {
	visited[a][b] = 1;
	q.push({ a,b });
	dist[a][b]++;

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int new_x = x + x_dir[i];
			int new_y = y + y_dir[i];
			if ((0 <= new_x and new_x < N) and (0 <= new_y and new_y < M) and !visited[new_x][new_y] and (input[new_x][new_y] == 1)) {
				visited[new_x][new_y] = 1;
				q.push({new_x,new_y});
				dist[new_x][new_y] = dist[x][y] + 1;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	std::cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < M; j++) input[i][j] = a[j] - '0';
	}
	bfs(0, 0);
	cout << dist[N - 1][M - 1];
}