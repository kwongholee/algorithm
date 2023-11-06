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

int n, k;
bool visited[100001];
queue<pair<int,int>> q;

int bfs(int n) {
	q.push({ n,0 });
	visited[n] = true;
	while (!q.empty()) {
		int x = q.front().first, count = q.front().second;
		q.pop();
		if (x == k) return count;
		if (x - 1 >= 0 and x - 1 <= 100000 and !visited[x - 1]) {
			q.push({ x - 1, count + 1 });
			visited[x - 1] = true;
		}
		if (x + 1 >= 0 and x + 1 <= 100000 and !visited[x + 1]) {
			q.push({ x + 1,count + 1 });
			visited[x + 1] = true;
		}
		if (x * 2 >= 0 and x * 2 <= 100000 and !visited[x * 2]) {
			q.push({ x * 2, count + 1 });
			visited[x * 2] = true;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	cout << bfs(n);
}