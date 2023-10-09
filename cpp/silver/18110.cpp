#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <deque>
#include <queue>
#include <set>

using namespace std;

int num, cnt = 0;
long long total = 0;
deque<int> dq;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> num;
	if (num == 0) cout << 0;
	else {
		for (int i = 0; i < num; i++) {
			int rank;
			cin >> rank;
			dq.push_back(rank);
		}
		sort(dq.begin(), dq.end());
		long double num2 = floor((double) num * 0.15 + 0.5);
		for (int i = 0; i < num2; i++) {
			dq.pop_front();
			dq.pop_back();
		}
		for (int i = 0; i < dq.size(); i++) {
			total += dq[i];
			cnt++;
		}
		cout << floor((double) total / (double) cnt + 0.5);
	}
}