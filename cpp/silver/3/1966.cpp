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

int num, a, b, p;
queue<pair<int, int>> q;
priority_queue<int> pq;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> num;
	for (int i = 0; i < num; i++) {
		int cnt = 0;
		cin >> a >> b;
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		for (int j = 0; j < a; j++) {
			cin >> p;
			q.push({ j,p });
			pq.push(p);
		}
		while (!q.empty()) {
			int location = q.front().first;
			int value = q.front().second;
			q.pop();
			if (value == pq.top()) {
				pq.pop();
				cnt+=1;
				if (b == location) {
					cout << cnt << '\n';
					break;
				}
			}
			else {
				q.push({ location, value });
			}
		}
	}
}