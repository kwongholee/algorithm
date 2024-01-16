#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;

int T;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        int N, M, W;
        cin >> N >> M >> W;
        vector<vector<pair<int, int>>> graph(N + 1);
        for (int i = 0; i < M; i++) {
            int S, E, T;
            cin >> S >> E >> T;
            graph[S].push_back({ E, T });
            graph[E].push_back({ S, T });
        }
        for (int i = 0; i < W; i++) {
            int S, E, T;
            cin >> S >> E >> T;
            graph[S].push_back({ E, -T });
        }
        vector<int> dist(N + 1, INF);
        dist[1] = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                for (auto edge : graph[j]) {
                    int next = edge.first;
                    int weight = edge.second;
                    if (dist[next] > dist[j] + weight) {
                        dist[next] = dist[j] + weight;
                        if (i == N) {
                            cout << "YES\n";
                            goto end;
                        }
                    }
                }
            }
        }
        cout << "NO\n";
    end:
        continue;
    }
}