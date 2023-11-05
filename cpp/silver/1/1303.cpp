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

// int N, M, push[4] = { 1,0, -1, 0 };
// char input[100][100], now;
// map<char, int> m = { {'W', 0}, {'B', 0} };

// int dfs(int a, int b) {
// 	if (a < 0 or a >= M or b < 0 or b >= N or input[a][b] != now) return 0;
// 	int cnt = 1;
// 	input[a][b] = 'N';
// 	for (int i = 0; i < 4; i++) {
// 		cnt += dfs(a + push[i], b + push[3 - i]);
// 	}
// 	return cnt;
// }

// int main() {
// 	cin.tie(NULL);
// 	std::cout.tie(NULL);
// 	ios_base::sync_with_stdio(false);

// 	cin >> N >> M;
// 	for (int i = 0; i < M; i++) {
// 		string s;
// 		cin >> s;
// 		for (int j = 0; j < N; j++) input[i][j] = s[j];
// 	}
// 	for (int i = 0; i < M; i++) {
// 		for (int j = 0; j < N; j++) {
// 			if (input[i][j] != 'N') {
// 				now = input[i][j];
// 				m[now] += pow(dfs(i, j), 2);
// 			}
// 		}
// 	}
// 	cout << m['W'] << " " << m['B'];
// }

int N, M, push_x[4] = { 1,0, -1, 0 }, push_y[4] = { 0,1,0,-1 };
char input[100][100], now;
bool visited[100][100] = { false };
map<char, int> m = { {'W', 0}, {'B', 0} };

int dfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	int cnt = 1;
	visited[a][b] = true;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int new_x = x + push_x[i], new_y = y + push_y[i];
			if (new_x >= 0 and new_x < M and new_y >= 0 and new_y < N) {
				if (input[new_x][new_y] == now and !visited[new_x][new_y]) {
					visited[new_x][new_y] = true;
					cnt++;
					q.push({ new_x, new_y });
				}
			}
		}
	}
	return pow(cnt, 2);
}

int main() {
	cin.tie(NULL);
	std::cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) input[i][j] = s[j];
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == false) {
				now = input[i][j];
				m[now] += dfs(i,j);
			}
		}
	}
	cout << m['W'] << " " << m['B'];
}