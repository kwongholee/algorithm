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
#include <cstring>

using namespace std;

int N;
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for(int i = 0; i < N; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			if (!pq.empty()) {
				cout << pq.top().second << '\n';
				pq.pop();
			}
			else cout << 0 << '\n';
		}
		else {
			if (x > 0) pq.push({ x, x });
			else pq.push({ (-1) * x, x });
		}
	}
}