#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V, E, n = 0, result = 0;
int parent[10001];
vector < pair<int, pair<int, int>>> v;

int findParent(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = findParent(parent[x]);
}

void uni(int x, int y) {
	x = findParent(x);
	y = findParent(y);
	parent[y] = x;
}

bool sameparent(int x, int y) {
	x = findParent(x);
	y = findParent(y);
	if (x == y) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ c,{a,b} });
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= V; i++) parent[i] = i;
	for (int i = 0; i < v.size(); i++) {
		if (!sameparent(v[i].second.first, v[i].second.second)) {
			uni(v[i].second.first, v[i].second.second);
			result += v[i].first;
		}
	}
	cout << result;
}