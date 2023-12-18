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

int N, value = 0;
char table[50][50];

int bfs(int i) {
    bool visited[50][50] = { false };
    queue<pair<int, int>> q;
    set<int> s;
    q.push({ i,0 });
    while (!q.empty()) {
        int x = q.front().first, cnt = q.front().second;
        q.pop();
        if (cnt == 2 and x != i) s.insert(x);
        else {
            if (cnt == 1) s.insert(x);
            for (int k = 0; k < N; k++) {
                if (table[x][k] == 'Y' and !visited[x][k]) {
                    q.push({ k, cnt + 1 });
                    visited[x][k] = true;
                }
            }
        }
    }
    return s.size();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) table[i][j] = s[j];
    }
    for (int i = 0; i < N; i++) value = max(value, bfs(i));
    cout << value;
}