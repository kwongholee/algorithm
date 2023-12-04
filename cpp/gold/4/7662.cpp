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

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		multiset<int, less<int>> ms;
		for (int k = 0; k < N; k++) {
			char c;
			int n;
			cin >> c >> n;
			if (c == 'I') {
				ms.insert(n);
			}
			else {
				if (ms.size() == 0) continue;
				else {
					if (n == 1) {
						multiset<int>::iterator x = --ms.end();
						ms.erase(x);
					}
					else {
						multiset<int>::iterator x = ms.begin();
						ms.erase(x);
					}
				}
			}
		}
		if (ms.size() == 0) cout << "EMPTY" << '\n';
		else cout << *--ms.end() << " " << *ms.begin() << '\n';
	}
}