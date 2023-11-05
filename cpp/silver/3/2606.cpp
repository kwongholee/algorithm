#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <set>

using namespace std;

int N, M, cnt = 0;
int input[101][101];
bool visited[101] = { 0, };
queue<int> q;

void bfs(int v) {
	q.push(v);
	visited[v] = true;

	while (!q.empty()) {
		v = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (input[v][i] == 1 and visited[i] == 0) {
				q.push(i);
				visited[i] = true;
				cnt++;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		input[a][b] = 1;
		input[b][a] = 1;
	}	
	bfs(1);
	cout << cnt;
}