#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	vector<int> v = { 2 };
	for (int i = a; i <= b; i++) {
		bool result = true;
		for (auto e : v) {
			if (i % e == 0) {
				result = false;
				break;
			}
		}
		if (result) {
			cout << i << '\n';
			v.push_back(i);
		} 
	}
}