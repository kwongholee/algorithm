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

int n, m, total = 999999;
int six = 1000, one = 1000;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a < six) six = a;
		if (b < one) one = b;
	}
	int d = n / 6;
	for (int i = 0; i <= d + 1; i++) {
		int a = six * i, b;
		if (i != d + 1) b = one * (n - 6 * i);
		else b = 0;
		if (total > a + b) total = a + b;
	}
	cout << total;
}