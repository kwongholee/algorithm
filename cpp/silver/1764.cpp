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

int N, M;
set<string> s;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	string a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		s.insert(a);
	}
	set<string> copy;
	for (int i = 0; i < M; i++) {
		cin >> a;
		if (!s.insert(a).second) copy.insert(a);
	}
	cout << copy.size() << '\n';
	for (auto e : copy) {
		cout << e << '\n';
	}
}