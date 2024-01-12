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

int n;
int arr[3], dp[3] = { 0,0,0 };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[0] >> arr[1] >> arr[2];
		int t0 = dp[0], t1 = dp[1], t2 = dp[2];
		dp[0] = min(t1, t2) + arr[0];
		dp[1] = min(t0, t2) + arr[1];
		dp[2] = min(t0, t1) + arr[2];
	}
	cout << min(dp[0], min(dp[1], dp[2]));
}