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

int T, n;
int table[10001];

void find(int a, int b) {
    int target_a = a, target_b = b;
    set<int> s;
    while (target_a != 0 and target_a <= n) {
        s.insert(target_a);
        target_a = table[target_a];
    }
    while (target_b != 0 and target_b <= n) {
        if (!s.insert(target_b).second) break;
        target_b = table[target_b];
    }
    cout << target_b << '\n';
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        for (int j = 0; j < n - 1; j++) {
            int a, b;
            cin >> a >> b;
            table[b] = a;
        }
        int target_x, target_y;
        cin >> target_x >> target_y;
        find(target_x, target_y);
    }
}