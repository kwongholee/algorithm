#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num;
	cin >> num;
	if (num % 3 == 0 || num % 3 == 2) cout << "CY";
	else cout << "SK";
}