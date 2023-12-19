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

int N, min_value = 999999;
bool table[51][51];
int value[51];
set<int> s;

int bfs(int n) {
    queue<pair<int, int>> q;
    bool visited[51] = { false };
    int cnt = 0;
    q.push({ n, 0 });
    visited[n] = true;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 1; i <= N; i++) {
            if (!visited[i] and table[x][i]) {
                visited[i] = true;
                q.push({ i, y + 1 });
                cnt = max(cnt, y + 1);
            }
        }
    }
    return cnt;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == -1 and b == -1) break;
        table[a][b] = true;
        table[b][a] = true;
    }
    for (int i = 1; i <= N; i++) {
        value[i] = bfs(i);
        min_value = min(min_value, value[i]);
    }
    for (int i = 1; i <= N; i++) {
        if (value[i] == min_value) s.insert(i);
    }
    cout << min_value << " " << s.size() << '\n';
    for (auto e : s) cout << e << " ";
}