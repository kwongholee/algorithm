#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a;
	cin >> a;
	vector<char> v;
	for (int i = 0; i < a.length(); i++) {
		v.push_back(a[i]);
	}
	sort(v.begin(), v.end());
	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i];
	}
}