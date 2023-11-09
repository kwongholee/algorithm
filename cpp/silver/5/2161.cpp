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

int n;
queue<int> q;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) q.push(i);
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
		if (!q.empty()) {
			q.push(q.front());
			q.pop();
		}
	}
}