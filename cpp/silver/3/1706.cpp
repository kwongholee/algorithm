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

int R, C;
char table[20][20];
vector<string> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++) table[i][j] = s[j];
    }
    for (int i = 0; i < R; i++) {
        string s = "";
        for (int j = 0; j < C; j++) {
            if (table[i][j] == '#') {
                if (s.size() > 1) v.push_back(s);
                s = "";
            }
            else s += table[i][j];
            if (j == C - 1 and s.size() > 1) v.push_back(s);
        }
    }
    for (int i = 0; i < C; i++) {
        string s = "";
        for (int j = 0; j < R; j++) {
            if (table[j][i] == '#') {
                if (s.size() > 1) v.push_back(s);
                s = "";
            }
            else s += table[j][i];
            if (j == R - 1 and s.size() > 1) v.push_back(s);
        }
    }
    sort(v.begin(), v.end());
    cout << v[0];
}