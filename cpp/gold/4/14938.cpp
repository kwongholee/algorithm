#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 987654321;
int N, M, R, value = 0;
int table[101], dist[101];
vector<pair<int, int>> v[101];

void dijkstra(int i) {
	int total = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, i });
	dist[i] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first, cur = pq.top().second;
		pq.pop();
		for (int j = 0; j < v[cur].size(); j++) {
			int next = v[cur][j].first, ncost = v[cur][j].second;
			if (dist[next] > cost + ncost and cost != INF and ncost != INF) {
				dist[next] = cost + ncost;
				pq.push({ dist[next], next });
			}
		}
	}
	for (int k = 1; k <= N; k++) {
		if (dist[k] <= M) total += table[k];
	}
	if (value < total) value = total;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> R;
	for (int i = 1; i <= N; i++) cin >> table[i];
	for (int i = 0; i < R; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	for (int i = 1; i <= N; i++) {
		fill_n(dist, 101, INF);
		dijkstra(i);
	}
	cout << value;
}