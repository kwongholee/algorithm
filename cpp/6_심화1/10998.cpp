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
	int result = 1;
	for (int i = 0; i < a.length(); i++) v.push_back(a[i]);
	for (int i = 0; i < a.length() / 2; i++) {
		if (v[i] != v[a.length() - i - 1]) result = 0;
	}
	cout << result;
}