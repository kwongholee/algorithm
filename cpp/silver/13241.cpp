#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long int num1, num2;
	cin >> num1 >> num2;
	vector<long long int> v;
	v.push_back(num1);
	v.push_back(num2);
	sort(v.begin(), v.end());
	if (v[1] % v[0] == 0) cout << num1;
	else {
		for (int i = 2;; i++) {
			if (v[1] % i == 0 and v[0] % i == 0) {
				if (v[1] % v[0] == 0) {
					cout << i * (v[0] / i) * (v[1] / i);
					break;
				}
			}
		}
	}
}