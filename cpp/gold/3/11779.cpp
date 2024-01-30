#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

const int INF = 1e9;
int n, m, start, finish;
int dist[1001], parent[1001];
vector<pair<int, int>> v[1001];
stack<int> s;

void dijkstra(int s) {
	for (int i = 1; i <= n; i++) dist[i] = INF;
	dist[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
	pq.push({ 0, s });
	while (!pq.empty()) {
		int cost = pq.top().first, cur = pq.top().second;
		pq.pop();
		if (dist[cur] < cost) continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first, ncost = v[cur][i].second;
			if (dist[next] > cost + ncost) {
				dist[next] = cost + ncost;
				parent[next] = cur;
				pq.push({ dist[next], next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	cin >> start >> finish;
	fill_n(parent, 1001, -1);
	dijkstra(start);
	int e = finish;
	while (e != -1) {
		s.push(e);
		e = parent[e];
	}
	cout << dist[finish] << '\n';
	cout << s.size() << '\n';
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}