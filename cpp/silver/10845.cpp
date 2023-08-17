#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num;
	cin >> num;
	vector<int> v;
	for (int i = 0; i < num; i++) {
		string a;
		cin >> a;
		if (a == "push") {
			int b; cin >> b;
			v.push_back(b);
		}
		else if (a == "pop") {
			if (v.size() == 0) cout << -1 << '\n';
			else {
				cout << v[0] << '\n';
				v.erase(v.begin() + 0);
			}
		}
		else if (a == "size") {
			cout << v.size() << '\n';
		}
		else if (a == "empty") {
			if (v.size() == 0) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (a == "front") {
			if (v.size() == 0) cout << -1 << '\n';
			else cout << v[0] << '\n';
		}
		else {
			if (v.size() == 0) cout << -1 << '\n';
			else cout << v[v.size() - 1] << '\n';
		}
	}
}