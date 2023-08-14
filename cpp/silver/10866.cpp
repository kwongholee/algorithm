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
	vector<int> v;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		if (a == "push_front" or a == "push_back") {
			int b;
			cin >> b;
			if (a == "push_front") {
				v.insert(v.begin(), b);
			}
			else {
				v.push_back(b);
			}
		}
		else if (a == "pop_front") {
			if (v.size() == 0) cout << -1 << '\n';
			else {
				cout << v[0] << '\n';
				v.erase(v.begin() + 0);
			}
		}
		else if (a == "pop_back") {
			if (v.size() == 0) cout << -1 << '\n';
			else {
				cout << v[v.size()-1] << '\n';
				v.pop_back();
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
			else {
				cout << v[0] << '\n';
			}
		}
		else {
			if (v.size() == 0) cout << -1 << '\n';
			else {
				cout << v[v.size()-1] << '\n';
			}
		}
	}
}