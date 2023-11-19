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

int T, M, N, x, y;

int gcd(int M, int N) {
    if (N == 0) return M;
    else return gcd(N, M % N);
}
int lcm(int M, int N) {
    return (M * N) / gcd(M, N);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> M >> N >> x >> y;
        int result = -1;
        int maxi = lcm(M, N);
        for (int k = x; k <= maxi; k += M) {
            int ny = k % N;
            if (ny == 0) ny = N;
            if (ny == y) {
                result = k;
                break;
            }
        }
        cout << result << '\n';
    }
}