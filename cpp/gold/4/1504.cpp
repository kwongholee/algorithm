#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 987654321;
int N, E, start, fin, result1 = INF, result2 = INF;
vector<pair<int, int>> v[801];
int dist[3][801];

void dijkstra(int i, int s) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,s });
	dist[i][s] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first, cur = pq.top().second;
		pq.pop();
		for (int j = 0; j < v[cur].size(); j++) {
			int next = v[cur][j].first, distance = v[cur][j].second;
			if (dist[i][next] > cost + distance) {
				dist[i][next] = cost + distance;
				pq.push({ dist[i][next], next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	cin >> start >> fin;
	fill_n(&dist[0][0], 3 * 801, INF);
	dijkstra(0, 1);
	dijkstra(1, start);
	dijkstra(2, fin);
	int a = dist[0][start], b = dist[2][N], c = dist[0][fin], d = dist[1][N], e = dist[1][fin];
	if (e != INF) {
		if (a != INF and b != INF) result1 = a + b + e;
		if (c != INF and d != INF) result2 = c + d + e;
	}
	if (result1 == INF and result2 == INF) cout << -1;
	else cout << min(result1, result2);
}