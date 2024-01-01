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

int N, K, CNT = 999999, num = 0;
bool flag = false;
bool visited[100001] = { false };

void dfs(int n, int k) {
    queue<pair<int, int>> q;
    q.push({ n, 0 });
    while (!q.empty()) {
        int x = q.front().first, cnt = q.front().second;
        q.pop();
        visited[x] = true;
        if (x == k and !flag) {
            CNT = cnt;
            flag = true;
        }
        if (x == k and flag and cnt == CNT) num++;
        if (2 * x <= 100000 and !visited[2 * x]) q.push({ 2 * x, cnt + 1});
        if (x - 1 >= 0 and !visited[x - 1]) q.push({ x - 1, cnt + 1 });
        if (x + 1 <= 100000 and !visited[x + 1]) q.push({ x + 1, cnt + 1 });
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    dfs(N, K);
    cout << CNT << '\n' << num;
}