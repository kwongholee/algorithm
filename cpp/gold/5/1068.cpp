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

int N, delete_N, cnt = 0;
int tree[50], child[50] = { 0 };
bool visited[50] = { false };
queue<int> q;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tree[i];
		child[tree[i]]++;
	}
	cin >> delete_N;
	q.push(delete_N);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		visited[x] = true;
		if (child[tree[x]] > 0) child[tree[x]]--;
		for (int i = 0; i < N; i++) {
			if (!visited[i] and tree[i] == x) q.push(i);
		}
	}
	for (int i = 0; i < N; i++) {
		if (child[i] == 0 and !visited[i]) cnt++;
	}
	cout << cnt;
}