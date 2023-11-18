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
string input[50];
bool visited[50][50];

void dfs(int x, int y) {
	char c = input[x][y];
	int a = x, b = y;
	visited[a][b] = true;
	while (a < N or b < M) {
		if (c == '-' and b + 1 < M and input[a][b + 1] == '-') {
			b++;
			visited[a][b] = true;
		}
		else if (c == '|' and a + 1 < N and input[a + 1][b] == '|') {
			a++;
			visited[a][b] = true;
		}
		else break;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> input[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
}