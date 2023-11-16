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
multiset<int> max_ms;
multiset<int,greater<int>> min_ms;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		for (int k = 0; k < N; k++) {
			char c;
			int n;
			cin >> c >> n;
			if (c == 'I') {
				max_ms.insert(n);
				min_ms.insert(n);
			}
			else {
				if(n == 1) {
					multiset<int>::iterator x = max_ms.begin();
					min_ms.erase(min_ms.find(*x));
					max_ms.erase(x);
				} else {
					multiset<int>::iterator x = min_ms.begin();
					max_ms.erase(max_ms.find(*x));
					min_ms.erase(x);
				}
			}
		}
		if (max_ms.size() == 0) cout << "EMPTY" << '\n';
		else cout << *max_ms.begin() << " " << *min_ms.begin() << '\n';
	}
}