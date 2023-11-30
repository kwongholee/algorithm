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
string p, s;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T;
    for (int h = 0; h < T; h++) {
        vector<int> v;
        cin >> p >> n >> s;
        int R1 = 0, R2 = 0, R = 0;
        string num = "";
        for (char c : s) {
            if (c == '[' || c == ',' || c == ']') {
                if (!num.empty()) {
                    v.push_back(stoi(num));
                    num = "";
                }
            }
            else num += c;
        }
        for (int i = 0; i < p.size(); i++) {
            if (p[i] == 'R') R++;
            else {
                if (R % 2 == 0) R2++;
                else R1++;
            }
        }
        if (n - (R1 + R2) < 0) cout << "error" << '\n';
        else {
            cout << "[";
            if (R % 2 == 1) {
                for (int i = n - R1 - 1; i >= R2; i--) {
                    if (i == R2) cout << v[i];
                    else cout << v[i] << ",";
                }
            }
            else {
                for (int i = R2; i < n - R1; i++) {
                    if (i == n - R1 - 1) cout << v[i];
                    else cout << v[i] << ",";
                }
            }
            cout << "]" << '\n';
        }
    }
}