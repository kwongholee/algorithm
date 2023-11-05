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

int n, table[1000001] = { 0,1 };
const int mod = 1000000000;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	if (n > 0) for (int i = 2; i <= n; i++) table[i] = (table[i - 1] + table[i - 2]) % mod;
	else if (n < 0) for (int i = 2; i <= abs(n); i++) table[i] = (table[i - 1] + table[i - 2]) % mod;
	if (n == 0) cout << 0 << '\n' << 0;
	else if (n > 0) cout << 1 << '\n' << table[n];
	else {
		if (abs(n) % 2 == 0) cout << -1 << '\n' << table[abs(n)];
		else cout << 1 << '\n' << table[abs(n)];
	}
}