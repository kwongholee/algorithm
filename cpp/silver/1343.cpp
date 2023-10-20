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

int cnt = 0, result = 1;
string a;
queue<int> q;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> a;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == 'X') cnt++;
		else {
			if (cnt != 0) {
				if (cnt % 2 == 1) result = 0;
				else q.push(cnt);
			};
			cnt = 0;
			q.push(-1);
		}
		if (i == a.length() - 1 and cnt > 0) {
			if (cnt % 2 == 1) result = 0;
			else q.push(cnt);
		}
	}
	if (result == 1) {
		while (!q.empty()) {
			int i = q.front();
			if (i == -1) cout << ".";
			if(i > 0) {
				for(int j = 0; j < i/4; j++) cout << "AAAA";
				i %= 4;
			}
			if (i == 2) cout << "BB";
			q.pop();
		}
	}
	else cout << -1;
}