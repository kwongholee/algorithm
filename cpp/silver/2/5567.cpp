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

int N, M, cnt = 0;
vector<int> v[501];
bool visited[501] = { false };

void bfs() {
    queue<pair<int, int>> q;
    visited[1] = true;
    q.push({ 1,0 });
    while (!q.empty()) {
        int n = q.front().first, num = q.front().second;
        q.pop();
        if (num == 2) cnt++;
        else {
            if (num == 1) cnt++;
            for (int i = 0; i < v[n].size(); i++) {
                int x = v[n][i];
                if (!visited[x] and num <= 1) {
                    visited[x] = true;
                    q.push({ x, num + 1 });
                }
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
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs();
    cout << cnt;
}