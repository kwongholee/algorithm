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
int weight[101], value[101];
int table[101][100001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> weight[i] >> value[i];
    for (int i = 1; i <= N; i++) {
        for (int w = 0; w <= K; w++) {
            if (weight[i] <= w) table[i][w] = max(table[i - 1][w], value[i] + table[i - 1][w - weight[i]]);
            else table[i][w] = table[i - 1][w];
        }
    }
    cout << table[N][K];
}