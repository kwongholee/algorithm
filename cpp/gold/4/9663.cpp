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

int N, cnt = 0;
int col[15];

bool promising(int i) {
    int k = 0;
    bool flag = true;
    while (k < i and flag) {
        if (col[i] == col[k] or abs(col[i] - col[k]) == i - k) flag = false;
        k++;
    }
    return flag;
}

void queens(int n) {
    if (promising(n)) {
        if (n == N - 1)  cnt++;
        else {
            for (int j = 0; j < N; j++) {
                col[n + 1] = j;
                queens(n + 1);
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    queens(-1);
    cout << cnt;
}