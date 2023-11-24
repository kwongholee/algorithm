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

int N;
string table[1000];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> table[i];
    int len = table[0].size();
    for (int i = len - 1; i >= 0; i--) {
        set<string> s;
        bool result = false;
        for (int j = 0; j < N; j++) {
            if (!s.insert(table[j].substr(i)).second) {
                result = true;
                break;
            }
        }
        if (!result) {
            cout << len - i;
            break;
        }
    }
}