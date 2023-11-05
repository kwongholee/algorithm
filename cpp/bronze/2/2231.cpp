#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <set>

using namespace std;

int num, i = 1, n = 1;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> num;
	while (true) {
		if (num / i > 0) {
			i *= 10;
			n += 1;
		}
		else {
			break;
		}
	}
	int test = num - 9 * n;
	while (true) {
		string a = to_string(test);
		int sum = test;
		for (int i = 0; i < a.size(); i++) {
			sum += (a[i] - '0');
		}
		if (sum == num) {
			cout << test;
			break;
		}
		else test++;
		if (test == num) {
			cout << 0;
			break;
		}
	}
}