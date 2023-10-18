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

int T;
string cloth[30];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		int total = 1;
		map<string, int> m;
		for (int j = 0; j < n; j++) {
			string kind;
			cin >> cloth[j] >> kind;
			if (m.find(kind) == m.end()) m.insert({ kind,1 });
			else m[kind]++;
		}
		for (auto e : m) total *= (e.second + 1);
		cout << total - 1 << '\n';
	}
}