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

int A, B, cnt = 1, k = 1;
int table[1001] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> A >> B;
    for (int i = 1; i <= B; i++) {
        table[i] = table[i - 1] + cnt;
        if (k == cnt) {
            k = 1;
            cnt++;
        }
        else k++;
    }
    cout << table[B] - table[A - 1];
}