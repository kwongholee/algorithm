#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <set>

using namespace std;

int n, m, num;
int cnt[10001] = { 0 };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		cnt[num]++;
	}
	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			cout << i << '\n';
		}
	}
}