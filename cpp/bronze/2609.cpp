#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>

using namespace std;

int m(int a, int b) {
	int i = 2;
	if (a % b == 0) return b;
	else {
		for (int i = 2; i <= b; i++) {
			if (b % i == 0) {
				if (a % (b / i) == 0) return (b / i);
			}
		}
	}
}
int M(int a, int b, int m) {
	return a*(b/m);
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	int mini = m(a, b);
	cout << mini << '\n';
	cout << M(a, b, mini);
}