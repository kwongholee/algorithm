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

int N, M, max_value = 1;
char table[50][50], target;

void find(int i, int j) {
    int flag = min(M - j - 1, N - i - 1);
    for (int k = 1; k <= flag; k++) {
        int x = table[i + k][j], y = table[i][j + k], xy = table[i + k][j + k];
        if (target == x and target == y and target == xy) max_value = max(max_value, (k + 1) * (k + 1));
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) table[i][j] = s[j];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            target = table[i][j];
            find(i,j);
        }
    }
    cout << max_value;
}