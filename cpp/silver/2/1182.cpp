#include <iostream>
#include <vector>

using namespace std;

int S, N, cnt = 0;
vector<int> v;

void dfs(int i, int t) {
    if (i == N) return;
    if (t + v[i] == S) cnt++;
    dfs(i + 1, t);
    dfs(i + 1, t + v[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    dfs(0, 0);
    cout << cnt;
}