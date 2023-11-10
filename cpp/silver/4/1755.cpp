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

int M, N, cnt = 0;
string table[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
priority_queue<pair<string, int>, vector<pair<string, int>>, greater<pair<string, int>>> pq;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> M >> N;
	for (int i = M; i <= N; i++) {
		int t = i / 10, o = i % 10;
		string s;
		if (t != 0) {
			s = table[t] + " " + table[o];
		}
		else {
			s = table[o];
		}
		pq.push({ s, i });
	}
	while (!pq.empty()) {
		cout << pq.top().second << " ";
		cnt++;
		if (cnt % 10 == 0) cout << '\n';
		pq.pop();
	}
}