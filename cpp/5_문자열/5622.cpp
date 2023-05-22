#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a;
	cin >> a;
	int total = a.length() * 2;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] >= 'A' and a[i] <= 'C') total += 1;
		else if (a[i] >= 'D' and a[i] <= 'F') total += 2;
		else if (a[i] >= 'G' and a[i] <= 'I') total += 3;
		else if (a[i] >= 'J' and a[i] <= 'L') total += 4;
		else if (a[i] >= 'M' and a[i] <= 'O') total += 5;
		else if (a[i] >= 'P' and a[i] <= 'S') total += 6;
		else if (a[i] >= 'T' and a[i] <= 'V') total += 7;
		else total += 8;
	}
	cout << total;
}