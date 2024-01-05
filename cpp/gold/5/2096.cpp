#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stack>

using namespace std;

int N;
int arr[3], mn_dp[3], mx_dp[3];


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    int t0, t1, t2;
    for (int i = 0; i < N; i++) {
        cin >> arr[0] >> arr[1] >> arr[2];
        t0 = mn_dp[0], t1 = mn_dp[1], t2 = mn_dp[2];
        mn_dp[0] = min(t0, t1) + arr[0];
        mn_dp[2] = min(t1, t2) + arr[2];
        mn_dp[1] = min(t1,min(t0,t2)) + arr[1];
        t0 = mx_dp[0], t1 = mx_dp[1], t2 = mx_dp[2];
        mx_dp[0] = max(t0, t1) + arr[0];
        mx_dp[2] = max(t1, t2) + arr[2];
        mx_dp[1] = max(t1, max(t0, t2)) + arr[1];
    }
    cout << max(mx_dp[0], max(mx_dp[1], mx_dp[2])) << " " << min(mn_dp[0], min(mn_dp[1], mn_dp[2]));
}