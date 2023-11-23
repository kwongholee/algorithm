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

int N, len;
char table[50];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        len = s.size();
        for (int j = 0; j < s.size(); j++) {
            if (i == 0) table[j] = s[j];
            else {
                if (s[j] != table[j]) table[j] = '?';
            }
        }
    }
    for (int i = 0; i < len; i++) cout << table[i];
}