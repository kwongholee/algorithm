#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num, total = 0;
	for (int i = 0; i < 5; i++) {
		cin >> num;
		total += num * num;
	}
	cout << total % 10;
}