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
	vector<long int> v;
	for (int i = 0; i < num; i++) {
		long int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	for (auto e : v) {
		cout << e << '\n';
	}
}