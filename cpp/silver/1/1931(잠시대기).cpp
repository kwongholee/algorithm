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

int n, cnt = 1, idx = 0;
pair<int, int> table[100000];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> table[i].first >> table[i].second;
	}
	sort(table, table + n);
	int start = table[0].first, end = table[0].second, i = 1;
	while (true) {
		if (table[i].first > start and table[i].second <= end) {
			end = table[i].second;
			idx = i;
			break;
		}
		else if (table[i].first > end) {
			idx = 0;
			break;
		}
		else i++;
	}
	for (int j = idx + 1; j < n; j++) {
		if (end < table[j].first) {
			cnt++;
			end = table[j].second;
		}
	}
	cout << cnt;
}