#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num = -1;
	while (true) {
		cin >> num;
		if (num != 0) {
			string copy = to_string(num);
			bool result = true;
			for (int i = 0; i < copy.size() / 2; i++) {
				if (copy[i] != copy[copy.size() - 1 - i]) {
					result = false;
					break;
				}
			}
			if (result) cout << "yes" << '\n';
			else cout << "no" << '\n';
		}
		else break;
	}
}