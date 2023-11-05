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

int N, M, cnt = 0;
vector<int> vect[1001];
int visited[1001];

void dfs(int x) {
	visited[x] = true;
	for (int i = 0; i < vect[x].size(); i++) {
		int idx = vect[x][i];
		if (visited[idx] == 0)
		{
			dfs(idx);
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		vect[u].push_back(v);
		vect[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0)
		{
			cnt++;
			dfs(i);
		}
	}
	cout << cnt;
}