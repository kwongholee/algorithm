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

int n, cnt = 1;
pair<int, int> table[100000];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> table[i].second >> table[i].first;
	}
	sort(table, table + n);
	int time = table[0].first;
	for (int j = 1; j < n; j++) {
		if (table[j].second >= time) {
			cnt++;
			time = table[j].first;
		}
	}
	cout << cnt;
}