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

const int INF = 1e9;
int n, m;
int table[101][101], result[101][101];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i != j) result[i][j] = INF;
        }
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (table[a][b] == 0 or table[a][b] > c) {
            table[a][b] = c;
            result[a][b] = c;
        }
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (result[i][k] != INF and result[k][j] != INF and result[i][j] > result[i][k] + result[k][j]) {
                    result[i][j] = result[i][k] + result[k][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (result[i][j] == INF) cout << 0 << " ";
            else cout << result[i][j] << " ";
        }
        cout << '\n';
    }
}
