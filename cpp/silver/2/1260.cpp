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

vector<int> graph[1001]; 
bool visited[1001]; 

void dfs(int x) { 
	visited[x] = true;
	cout << x << " ";

	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visited[y]) dfs(y);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) { 
		int x = q.front();
		q.pop();
		cout << x << " ";

		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visited[y]) {
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, v;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(v);
	cout << '\n';
	memset(visited, 0, n + 1);
	bfs(v);
}