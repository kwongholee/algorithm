#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>

using namespace std;

int N, M, answer;
bool btn[10];

int find(int n) {
    if (n == 0) {
        if (btn[n]) return 0;
        else return 1;
    }
    else {
        int cnt = 0;
        while (n > 0) {
            if (btn[n % 10]) return 0;
            else {
                cnt += 1;
                n /= 10;
            }
        }
        return cnt;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        btn[a] = true;
    }
    answer = abs(N - 100);
    for (int i = 0; i <= 1000000; i++) {
        int x = i;
        int len = find(x);
        if (len > 0) {
            int press = abs(x - N);
            if (answer > press + len) answer = press + len;
        }
    }
    cout << answer;
}