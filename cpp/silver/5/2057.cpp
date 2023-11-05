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

long long n;

string fact(long long n) {
	if (n == 0) return "NO";
	long long f = 1, total = n, i = 1;
	vector<long long> v = { 1 };
	while (true) {
		if (f <= n) {
			f *= i;
			v.push_back(f);
			i++;
		}
		else break;
	}
	for (int k = v.size() - 1; k >= 0; k--) {
		if (total >= v[k]) total -= v[k];
		if (total == 0) break;
	}
	if (total == 0) return "YES";
	return "NO";
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	cout << fact(n);
}