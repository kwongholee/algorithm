#include <iostream>
#include <vector>

using namespace std;

int N, M, i = 0;
bool visited[2001] = { false }, flag = false;
vector<int> v[2001];

void track(int n, int cnt) {
	visited[n] = true;
	if (cnt == 5) {
		flag = true;
		return;
	}
	for (int k = 0; k < v[n].size(); k++) {
		int e = v[n][k];
		if (!visited[e]) {
			track(e, cnt + 1);
			visited[e] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	while (!flag and i < N) {
		track(i, 1);
		visited[i] = false;
		i++;
	}
	if (flag) cout << 1;
	else cout << 0;
}