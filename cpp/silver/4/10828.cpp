#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a;
	cin >> a;
	vector<int> v;
	for (int i = 0; i < a; i++) {
		string b;
		cin >> b;
		if (b == "push") {
			int c;
			cin >> c;
			v.push_back(c);
		}
		else if (b == "pop") {
			if (v.size() == 0) cout << -1 << '\n';
			else {
				cout << v[v.size()-1] << '\n';
				v.pop_back();
			}
		}
		else if (b == "top") {
			if (v.size() == 0) cout << -1 << '\n';
			else {
				cout << v[v.size() - 1] << '\n';
			}
		}
		else if (b == "empty") {
			if (v.size() == 0) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else {
			cout << v.size() << '\n';
		}
	}
}