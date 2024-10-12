#include <bits/stdc++.h>

using namespace std;

int N, cnt = 1;
string firstSmallNum[4] = {"2","3","5","7"};
queue<string> q;

bool isPrime(int n) {
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    if(N == 1) {
        for(int i = 0; i < 4; i++) cout << stoi(firstSmallNum[i]) << '\n';
    }
    else {
        for(int i = 0; i < 4; i++) q.push(firstSmallNum[i]);
        while(!q.empty()) {
            string s = q.front();
            q.pop();
            for(int k = 1; k <= 9; k++) {
                int target = stoi(s) * 10 + k;
                if(isPrime(target)) {
                    string s2 = to_string(target);
                    if(s2.length() == N) cout << target << '\n';
                    else q.push(s2);
                }
            }
        }
    }
}
