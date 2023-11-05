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
	int three, five, result;
	vector<int> v;
	for (int i = 0; i <= a / 5; i++) {
		if ((a - 5 * i) % 3 == 0) {
			five = i;
			three = (a - 5 * i) / 3;
			int total = three + five;
			v.push_back(total); 
		}
	}
	if (v.size() == 0) cout << -1;
	else {
		for (int i = 0; i < v.size(); i++) {
			if (i == 0) result = v[0];
			else {
				if (result > v[i]) result = v[i];
			}
		}
		cout << result;
	}
}