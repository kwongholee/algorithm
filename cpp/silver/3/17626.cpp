#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <set>

using namespace std;

int N;
int table[50001] = {0, 1};

bool is_sqrt(int n) {
    int root = static_cast<int>(sqrt(n));
    return root * root == n ? true : false;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        table[i] = 5;
        if (is_sqrt(i)) table[i] = 1;
        else {
            for (int j = 1; j <= i / 2; j++) {
                if (table[i] > table[j] + table[i - j]) table[i] = table[j] + table[i - j];
            }
        }
    }
    cout << table[N];
}