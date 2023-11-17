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
priority_queue<int> max_pq;
priority_queue<int, vector<int>, greater<int>> min_pq;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> T;
	for (int i = 0; i < T; i++) {
		int N, insert_cnt = 0, delete_cnt = 0;
		cin >> N;
		for (int k = 0; k < N; k++) {
			char c;
			int n;
			cin >> c >> n;
			if (c == 'I') {
				max_pq.push(n);
				min_pq.push(n);
				insert_cnt++;
			}
			else {
				if (delete_cnt < insert_cnt) {
					if (n == 1) max_pq.pop();
					else min_pq.pop();
					delete_cnt++;
				}
			}
		}
		if (insert_cnt == delete_cnt) cout << "EMPTY" << '\n';
		else cout << max_pq.top() << " " << min_pq.top() << '\n';
	}
}