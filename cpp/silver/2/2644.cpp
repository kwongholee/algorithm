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

int n, m, target_X, target_Y;
int table[101][101];
int visited[101];

void bfs(int x) {
    queue<int> q;
    q.push(x);

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (table[top][i] == 1 and !visited[i]) {
                q.push(i);
                visited[i] = visited[top] + 1;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> target_X >> target_Y >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        table[a][b] = 1;
        table[b][a] = 1;
    }
    bfs(target_X);
    if (visited[target_Y] == 0) visited[target_Y] = -1;
    cout << visited[target_Y];
}