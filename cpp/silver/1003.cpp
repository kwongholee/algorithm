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

int T;
pair<int, int> fib[41];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i <= 40; i++) {
		if (i == 0) fib[i] = { 1,0 };
		else if (i == 1) fib[i] = {0, 1};
		else {
			int first = fib[i - 1].first + fib[i - 2].first;
			int second = fib[i - 1].second + fib[i - 2].second;
			fib[i] = { first,second };
		}
	}
	cin >> T;
	for (int i = 0; i < T; i++) {
		int a;
		cin >> a;
		cout << fib[a].first << " " << fib[a].second << '\n';
	}
}