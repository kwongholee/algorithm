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

int N, M, cnt = 0;
string s;
vector<int> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> s;
    if (N >= 500000 or 2 * N + 1 > M) cout << cnt;
    else {
        int n = 0;
        bool result = false;
        for (int i = 0; i < M - 2; i++) {
            if (!result and s[i] == 'I' and s[i + 1] == 'O' and s[i + 2] == 'I') {
                result = true;
                n++;
                i++;
            }
            else if (result and s[i + 1] == 'O' and s[i + 2] == 'I') {
                n++;
                i++;
            }
            else {
                if (n != 0) v.push_back(n);
                n = 0;
                result = false;
            }
        }
        if (n != 0) v.push_back(n);
        for (auto e : v) {
            if (e - N + 1 > 0) cnt += e - N + 1;
        }
        cout << cnt;
    }
}