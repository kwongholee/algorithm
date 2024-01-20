#include <bits/stdc++.h>

using namespace std;

int V, maxIdx = 0, maxValue = 0;
vector<pair<int, int>> tree[100001];
bool visited[100001] = { false };

void dfs(int n, int d) {
    if (maxValue < d) {
        maxValue = d;
        maxIdx = n;
    }
    for (int i = 0; i < tree[n].size(); i++) {
        int next = tree[n][i].first, distance = tree[n][i].second;
        if (!visited[next]) {
            visited[n] = true;
            dfs(next, d + distance);
            visited[n] = false;
        }
    }
    return;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> V;
    for (int i = 0; i < V; i++) {
        int a;
        cin >> a;
        while (true) {
            int b, c;
            cin >> b;
            if (b == -1) break;
            cin >> c;
            tree[a].push_back({ b,c });
        }
    }
    visited[1] = true;
    dfs(1, 0);
    memset(visited, false, sizeof(visited));
    visited[maxIdx] = true;
    dfs(maxIdx, 0);
    cout << maxValue;
}