#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

int T;

void DSLR(int a, int b) {
    queue<pair<string, int>> q;
    vector<bool> visited(10000, false); 
    q.push({ "", a });
    visited[a] = true;
    while (!q.empty()) {
        string instruction = q.front().first;
        int m = q.front().second;
        q.pop();
        if (m == b) {
            cout << instruction << '\n';
            return;
        }
        int D = (2 * m) % 10000;
        int S = (m == 0) ? 9999 : m - 1;
        int L = (m % 1000) * 10 + m / 1000;
        int R = (m % 10) * 1000 + m / 10;
        if (!visited[D]) {
            q.push({ instruction + "D", D });
            visited[D] = true;
        }
        if (!visited[S]) {
            q.push({ instruction + "S", S });
            visited[S] = true;
        }
        if (!visited[L]) {
            q.push({ instruction + "L", L });
            visited[L] = true;
        }
        if (!visited[R]) {
            q.push({ instruction + "R", R });
            visited[R] = true;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T;
    for (int k = 0; k < T; k++) {
        int a, b;
        cin >> a >> b;
        DSLR(a, b);
    }
}
