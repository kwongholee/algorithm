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

int N, M, cnt = 9999;
int ladder[101], snake[101];

void find() {
	queue<pair<int,int>> q;
	q.push({ 1,0 });
	while (!q.empty()) {
		int target = q.front().first, n = q.front().second, max_i = 0;
		q.pop();
		if (target < 100) {
			for (int i = 1; i <= 6; i++) {
				int new_target = target + i;
				if (new_target <= 100) {
					if (ladder[new_target] > 0) q.push({ new_target + ladder[new_target], n + 1 });
					else if (snake[new_target] > 0) q.push({ new_target - snake[new_target], n + 1 });
					else max_i = i;
				}

			}
			if (max_i != 0) q.push({ target + max_i, n + 1 });
		}
		else {
			cnt = n;
			break;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		ladder[a] = b - a;
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		snake[a] = a - b;
	}
	find();
	cout << cnt;
}