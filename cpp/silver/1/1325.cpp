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

using namespace std;

int N, M, max_v = 0;
int cnt[10001];
vector<int> v[10001];
bool visited[10001];
set<int> s;

int bfs(int i) {
    int cnt = 1;
    queue<int> q;
    visited[i] = true;
    q.push(i);
    while (!q.empty()) {
        int top = q.front();
        cnt++;
        q.pop();
        for (int k = 0; k < v[top].size(); k++) {
            int a = v[top][k];
            if (!visited[a]) {
                q.push(v[top][k]);
                cnt++;
                visited[a] = true;
            }
        }
    }
    return cnt;
}

void resetVisited() {
    for (int i = 0; i <= N; i++) visited[i] = false;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }
    for (int i = 1; i <= N; i++) {
        cnt[i] = bfs(i);
        resetVisited();
        max_v = max(max_v, cnt[i]);
    }
    for (int i = 1; i <= N; i++) {
        if (cnt[i] == max_v) s.insert(i);
    }
    for (auto e : s) cout << e << " ";
}