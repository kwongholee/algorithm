#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<string> v;
	for (int i = 1; i < 2 * n; i++) {
		if (i <= n) {
			string a(2 * i - 1, '*');
			string b(n - i, ' ');
			string c = b + a;
			v.push_back(c);
		}
		else {
			string a = v[2 * (n - 1) - i + 1];
			v.push_back(a);
		}
	}
	for (auto e : v) {
		cout << e << endl;
	}
}