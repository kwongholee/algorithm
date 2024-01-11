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

int n, max_value = 0, st = 0, en = 0;
int A[1001], dp[1001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) dp[i] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (A[i] > A[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	sort(dp, dp + n + 1);
	cout << dp[n];
}