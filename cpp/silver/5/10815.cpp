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
set<int> s;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		s.insert(a);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int b;
		cin >> b;
		if (s.insert(b).second) cout << 0 << " ";
		else cout << 1 << " ";
	}
}