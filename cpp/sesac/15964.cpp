#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void func(long long a, long long b) {
	cout << (a + b) * (a - b);
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long a, b;
	cin >> a >> b;
	func(a, b);
}