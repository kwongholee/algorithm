#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, result = -1;
int table[1000][1000][2], push_x[4] = { -1,0,1,0 }, push_y[4] = { 0,-1,0,1 };

int bfs(int n, int m) {
    queue<pair<int, pair<int, int>>> q;
    q.push({ 0,{0,0} });
    while (!q.empty()) {
        int broken = q.front().first, x = q.front().second.first, y = q.front().second.second;
        q.pop();
        if (x == n - 1 and y == m - 1) return table[n - 1][m - 1][broken] + 1;
        for (int i = 0; i < 4; i++) {
            int new_x = x + push_x[i], new_y = y + push_y[i];
            if (new_x < 0 or new_x >= n or new_y < 0 or new_y >= m) continue;
            if (table[new_x][new_y][0] == 1) {
                if (!broken) {
                    table[new_x][new_y][broken + 1] = table[x][y][broken] + 1;
                    q.push({ 1,{new_x, new_y} });
                }
            }
            else if (table[new_x][new_y][0] == 0) {
                if (broken == 1 and table[new_x][new_y][broken]) continue;
                table[new_x][new_y][broken] = table[x][y][broken] + 1;
                q.push({ broken, {new_x,new_y} });
            }
        }
    }
    return -1;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) table[i][j][0] = s[j] - '0';
    }
    cout << bfs(N, M);
}