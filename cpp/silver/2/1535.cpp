#include <iostream>

using namespace std;

int N, value = 0;
int hp[20], glad[20];
bool visited[20] = { false };

void dfs(int n, int g, int h) {
	if (h - hp[n] > 0 and n != N) {
		visited[n] = true;
		for (int i = n + 1; i <= N; i++) dfs(i, g + glad[n], h - hp[n]);
		visited[n] = false;
	}
	else {
		if (g > value) value = g;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> hp[i];
	for (int i = 0; i < N; i++) cin >> glad[i];
	for (int i = 0; i < N; i++) dfs(i, 0, 100);
	cout << value;
}