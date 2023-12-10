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

int N;
int table[100001];
vector<int> v[100001];

void bfs() {
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int idx = v[x][i];
			if (idx != 1) {
				if (table[idx] == 0) {
					table[idx] = x;
					q.push(idx);
				}
				else if (table[x] == 0) {
					table[x] = idx;
					q.push(x);
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int k = 0; k < N-1; k++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs();
	for (int i = 2; i <= N; i++) cout << table[i] << '\n';
}