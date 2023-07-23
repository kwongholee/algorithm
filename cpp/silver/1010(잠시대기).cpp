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
	for (int i = 0; i < a; i++) {
		int b, c, result, m = 1, n = 1;
		cin >> b >> c;
		if (b == c) result = 1;
		else if (b < c - b) {
			for (int j = 1; j < b+1; j++) {
				m *= c - j + 1;
				n *= j;
			}
			result = m / n;
			cout << result << endl;
		}
		else {
			for (int j = 1; j < c-b+1; j++) {
				m *= c - j + 1;
				n *= j;
			}
			result = m / n;
			cout << result << endl;
		}
	}
}