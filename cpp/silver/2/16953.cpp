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

int A, B;
set<int> s;

int bfs(int start, int target) {
	queue<pair<long long, int>> q;
	q.push({ start, 1 });
	s.insert(start);
	while (!q.empty()) {
		long long int n = q.front().first, t = q.front().second;
		q.pop();
		if (n == target) return t;
		long long next1 = 10 * n + 1, next2 = 2 * n;
		if (next1 <= target and s.insert(next1).second) q.push({ next1, t + 1 });
		if (next2 <= target and s.insert(next2).second) q.push({ next2, t + 1 });
	}
	return -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> A >> B;
	cout << bfs(A, B);
}