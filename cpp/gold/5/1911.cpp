#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L, cnt = 0, up = 0;
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        v.push_back({ start, end });
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        if (v[i].first > up) up = v[i].first;
        while (up < v[i].second) {
            up += L;
            cnt++;
        }
    }
    cout << cnt;
}