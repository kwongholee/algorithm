#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int N, M, start, fin;
int dist[1001];
vector<pair<int,int>> d[1001];

void Dijkstra(int s) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, s });
	dist[s] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first, cur = pq.top().second;
		pq.pop();
		if (dist[cur] < cost) continue;
		for (int i = 0; i < d[cur].size(); i++) {
			int next = d[cur][i].first, ncost = d[cur][i].second;
			if (dist[next] > cost + ncost) {
				dist[next] = cost + ncost;
				pq.push({ dist[next], next });
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
		int a, b, c;
		cin >> a >> b >> c;
		d[a].push_back({ b,c });
	}
	cin >> start >> fin;
	fill_n(dist, N + 1, INF);
	Dijkstra(start);
	cout << dist[fin];
}