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

int N, M;
set<int> A, B;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A.insert(a);
	}
	for (int i = 0; i < M; i++) {
		int b;
		cin >> b;
		B.insert(b);
	}
	for (auto e : B) {
		A.erase(e);
	}
	if (A.empty()) cout << 0;
	else {
		cout << A.size() << '\n';
		for (auto e : A) cout << e << " ";
	} 
}