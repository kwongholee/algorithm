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

int N, K, input[50], two_cnt = 0, three_cnt = 0;
deque<int> dq;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) dq.push_back(i);
	for (int i = 0; i < K; i++) cin >> input[i];
	for (int i = 0; i < K; i++) {
		int j = input[i] - 1 - i - two_cnt + three_cnt;
		if (dq.size() / 2 > j) {
			for (int k = 0; k < j; k++) {
				dq.push_back(dq.front());
				dq.pop_front();
				two_cnt++;
			}
		}
		else {
			for (int k = 0; k < dq.size()-j; k++) {
				dq.push_front(dq.back());
				dq.pop_back();
				three_cnt++;
			}
		}
		dq.pop_front();
	}
	cout << two_cnt + three_cnt;
}