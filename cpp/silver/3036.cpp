#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num, k;
	cin >> num;
	vector<int> v;
	for (int i = 0; i < num; i++) {
		if (i == 0) {
			cin >> k;
		}
		else {
			int a;
			cin >> a;
			v.push_back(a);
		}
	}
	for (auto e : v) {
		if (k % e == 0) {
			cout << k / e << "/1" << '\n';
		}
		else {
			for (int i = 2; i <= e;i++) {
				if (e % i == 0) {
					if (k % (e / i) == 0) {
						cout << k / (e / i) << "/" << i << '\n';
						break;
					}
				}
				if (i == e) {
					cout << k << "/" << e << '\n';	
				}
			}
		}
	}
}