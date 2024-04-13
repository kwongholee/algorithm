#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

long long int N, P, Q, cnt = 0;

void bfs(int s) {
    priority_queue<int> pq;
    pq.push(s);
    while (!pq.empty()) {
        long long int n = pq.top();
        pq.pop();
        if (n == 0) cnt++;
        else {
            long long int a = floor(n / P), b = floor(n / Q);
            pq.push(a);
            pq.push(b);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> P >> Q;
    bfs(N);
    cout << cnt;
}