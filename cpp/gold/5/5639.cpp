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

int n;
vector<int> v;

void go(int st, int en) {
	if (st >= en) return;
	if (st == en - 1) {
		cout << v[st] << '\n';
		return;
	}
	int idx = st + 1;
	while (idx < en) {
		if (v[st] < v[idx]) break;
		idx++;
	}
	go(st + 1, idx);
	go(idx, en);
	cout << v[st] << '\n';
	return;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (cin >> n) v.push_back(n);
	go(0, v.size());
}