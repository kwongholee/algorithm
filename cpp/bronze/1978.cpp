#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num, cnt = 0;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int a;
		cin >> a;
		if (a == 1) continue;
		else {
			bool result = true;
			for (int k = 2; k <= sqrt(a); k++) {
				if (a % k == 0) {
					result = false;
					break;
				}
			}
			if (result == true) cnt++;
		}
	}
	cout << cnt;
}