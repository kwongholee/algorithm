#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;
	string num = to_string(a * b * c);
	vector<int> v(10);
	for (int i = 0; i < num.length(); i++) {
		v[num[i]-'0']++;
	}
	for (auto e : v) {
		cout << e << '\n';
	}
}