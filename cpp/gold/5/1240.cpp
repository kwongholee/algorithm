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

using namespace std;

int N, M;
int tree[1001][1001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N - 1; i++) {
		int a, b, n;
		cin >> a >> b >> n;
		tree[a][b] = n;
		tree[b][a] = n;
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		stack<pair<int, int>> s;
		s.push({ a,0 });
		bool visited[1001] = { false };
		while (!s.empty()) {
			int x = s.top().first, cnt = s.top().second;
			visited[x] = true;
			if (x == b) {
				cout << cnt << '\n';
				break;
			}
			for (int i = 1; i <= N; i++) {
				if (!visited[i] and tree[x][i] != 0) {
					s.push({ i, cnt + tree[x][i] });
					break;
				}
				if (i == N) s.pop();
			}
		}
	}
}