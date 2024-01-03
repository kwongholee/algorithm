#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = 999999;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E, start;
    cin >> V >> E >> start;

    vector<vector<pair<int, int>>> graph(V + 1);

    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
    }

    vector<int> dist(V + 1, INF);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) continue;

        for (const auto& edge : graph[cur]) {
            int next = edge.first;
            int nextCost = cost + edge.second;

            if (nextCost < dist[next]) {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }

    for (int i = 1; i <= V; ++i) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }

    return 0;
}
