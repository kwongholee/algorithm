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

int min_val, num_cnt = 0, oper_cnt = 0;
string s;
int num[25];
char oper[25];
vector<int> sub;

void find(int a, int b) {
    for (int j = a + 2; j <= b; j++) {
        num[a + 1] += num[j];
        num[j] = 0;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> s;
    string a = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+' or s[i] == '-') {
            int b = stoi(a);
            num[num_cnt++] = b;
            a = "";
            oper[oper_cnt++] = s[i];
            if (s[i] == '-') sub.push_back(oper_cnt - 1);
        }
        else if (i == s.size() - 1) {
            a += s[i];
            int b = stoi(a);
            num[num_cnt++] = b;
            sub.push_back(oper_cnt);
        }
        else a += s[i];
    }
    for (int i = 0; i < sub.size() - 1; i++) find(sub[i], sub[i + 1]);
    min_val = num[0];
    for (int k = 0; k < num_cnt - 1; k++) {
        if (oper[k] == '+') min_val += num[k + 1];
        else min_val -= num[k + 1];
    }
    cout << min_val;
}