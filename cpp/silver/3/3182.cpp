#include <iostream>
#include <cstring>

using namespace std;

int n, result = 0, cnt = 0, start;
int table[1001];
int visited[1001] = { false };

void dfs(int i, int c) {
	if (visited[i]) {
		if (c > cnt) {
			cnt = c;
			result = start;
		}
		return;
	}
	visited[i] = 1;
	dfs(table[i], c + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> table[i];
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		start = i;
		dfs(i, 0);
	}
	cout << result;
}