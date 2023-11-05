#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	if (b > a / 2) {
		int M=1, N=1;
		for (int i = 1; i <= a - b; i++) {
			N *= i;
			M *= (a - i + 1);
		}
		cout << M / N;
	}
	else {
		int M = 1, N = 1;
		for (int i = 1; i <= b; i++) {
			N *= i;
			M *= (a - i + 1);
		}
		cout << M / N;
	}
}