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

int N;
int table[25][25], push_x[4] = { -1,0,1,0 }, push_y[4] = { 0,-1,0,1 };
priority_queue<int, vector<int>, greater<int>> pq;

void dfs(int a, int b) {
	int cnt = 1;
	table[a][b] = 0;
	stack<pair<int, int>> s;
	s.push({ a,b });
	while (!s.empty()) {
		int x = s.top().first, y = s.top().second;
		for (int i = 0; i < 4; i++) {
			int new_x = x + push_x[i], new_y = y + push_y[i];
			if (0 <= new_x and new_x < N and 0 <= new_y and new_y < N and table[new_x][new_y] == 1) {
				s.push({ new_x,new_y });
				table[new_x][new_y] = 0;
				cnt++;
			}
		}
		if (x == s.top().first and y == s.top().second) s.pop();
	}
	pq.push(cnt);
}

void bfs(int a, int b) {
	int cnt = 1;
	table[a][b] = 0;
	queue<pair<int, int>> q;
	q.push({ a,b });
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		for (int i = 0; i < 4; i++) {
			int new_x = x + push_x[i], new_y = y + push_y[i];
			if (0 <= new_x and new_x < N and 0 <= new_y and new_y < N and table[new_x][new_y] == 1) {
				q.push({ new_x,new_y });
				table[new_x][new_y] = 0;
				cnt++;
			}
		}
		if (x == q.front().first and y == q.front().second) q.pop();
	}
	pq.push(cnt);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			table[i][j] = s[j] - '0';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (table[i][j] == 1) dfs(i, j);
		}
	}
	cout << pq.size() << '\n';
	while (!pq.empty()) {
		cout << pq.top() << '\n';
		pq.pop();
	}
}