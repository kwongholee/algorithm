#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;

int N, M, X, s, e, t, value = 0;
vector<pair<int, int>> graph[1001];
int dst[1001], ans[1001];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });
    dst[start] = 0;
    while (!pq.empty()) {
        int cost = pq.top().first, now = pq.top().second;
        pq.pop();
        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].first, nCost = graph[now][i].second;
            if (cost + nCost < dst[next]) {
                dst[next] = cost + nCost;
                pq.push({ cost + nCost, next });
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> X;
    for (int i = 1; i <= N; i++) dst[i] = INF;
    for (int i = 0; i < M; i++) {
        cin >> s >> e >> t;
        graph[s].push_back({ e,t });
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) dst[j] = INF;
        dijkstra(i);
        ans[i] = dst[X];
    }
    for (int i = 1; i <= N; i++) dst[i] = INF;
    dijkstra(X);
    for (int i = 1; i <= N; i++) {
        ans[i] += dst[i];
        value = max(ans[i], value);
    }
    cout << value;
}