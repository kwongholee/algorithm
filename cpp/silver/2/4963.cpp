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

int w, h, table[50][50];
int push_x[8] = { 1,0,-1,0,-1,-1,1,1 };
int push_y[8] = { 0,1,0,-1,-1,1,-1,1 };

void bfs(int a, int b) {
    queue<pair<int, int>> q;
    q.push({ a,b });
    table[a][b] = 0;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int new_x = x + push_x[i], new_y = y + push_y[i];
            if (table[new_x][new_y] == 1 and 0 <= new_x and new_x < h and 0 <= new_y and new_y < w) {
                table[new_x][new_y] = 0;
                q.push({ new_x, new_y });
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (true) {
        cin >> w >> h;
        if (w == 0 and h == 0) break;
        int cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> table[i][j];
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (table[i][j] != 0) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}