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

int N, M;
int table[1025][1025], dp[1025][1025];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) cin >> table[i][j];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) dp[i][j] = table[i][j] + dp[i][j - 1];
    }
    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2, total = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int h = x1; h <= x2; h++) total += (dp[h][y2] - dp[h][y1 - 1]);
        cout << total << '\n';
    }
}