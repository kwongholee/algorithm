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

int E, S, M;
int e = 1, s = 1, m = 1, cnt = 1;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> E >> S >> M;
	while (true) {
		if (e == E and s == S and m == M) break;
		else {
			if (e >= 15) e = 1;
			else e++;
			if (s >= 28) s = 1;
			else s++;
			if (m >= 19) m = 1;
			else m++;
			cnt++;
		}
	}
	cout << cnt;
}