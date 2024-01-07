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

int N, K, ans = 0, two_cnt = 0, three_cnt = 0;
deque<int> dq;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) dq.push_back(i);
	while (K--) {
		int num;
		cin >> num;
		for (int i = 0; i < dq.size(); i++) {
			if (dq[i] == num) {
				two_cnt = i;
				three_cnt = dq.size() - i;
			}
		}
		if (two_cnt <= three_cnt) {
			while (true) {
				if (dq.front() == num) {
					dq.pop_front();
					break;
				}
				dq.push_back(dq.front());
				dq.pop_front();
				ans++;
			}
		}
		else {
			ans++;
			while (true) {
				if (dq.back() == num) {
					dq.pop_back();
					break;
				}
				dq.push_front(dq.back());
				dq.pop_back();
				ans++;
			}
		}
	}
	cout << ans;
}