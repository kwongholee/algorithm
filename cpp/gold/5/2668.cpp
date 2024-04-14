#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;
int arr[101];
bool visit[101];
vector<int> result;

void dfs(int n, int start) {
    if (visit[n]) {
        if (start == n) result.push_back(n);
        return;
    }
    visit[n] = true;
    dfs(arr[n], start);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 1; i <= N; i++) {
        memset(visit, 0, sizeof(visit));
        dfs(i, i);
    }
    cout << result.size() << '\n';
    for (auto e : result) cout << e << '\n';
}