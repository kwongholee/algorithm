#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;
	vector<string> v;
	vector<int> v2;
	v.push_back(a);
	v.push_back(b);
	for (auto e : v) {
		char t = e[2];
		e[2] = e[0];
		e[0] = t;
		v2.push_back(stoi(e));
	}
	int Max = max(v2[0], v2[1]);
	cout << Max;
}