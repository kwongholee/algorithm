#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stack>

using namespace std;

int N, K;
bool visited[100001] = { false };

int dfs(int n, int k) {
    queue<pair<int, int>> q;
    q.push({ n, 0 });
    visited[n] = true;
    while (!q.empty()) {
        int x = q.front().first, cnt = q.front().second;
        q.pop();
        if (x == k) return cnt;
        if (2 * x <= 100000 and !visited[2 * x]) {
            q.push({ 2 * x, cnt});
            visited[2 * x] = true;
        }
        if (x - 1 >= 0 and !visited[x - 1]) {
            q.push({ x - 1, cnt + 1 });
            visited[x - 1] = true;
        }
        if (x + 1 <= 100000 and !visited[x + 1]) {
            q.push({ x + 1, cnt + 1 });
            visited[x + 1] = true;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    cout << dfs(N, K);
}