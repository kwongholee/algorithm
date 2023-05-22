#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a;
	int cnt = 0;
	getline(cin, a);
	for (int i = 0; i < a.length(); i++) {
		if (a[i] >= 'A' and a[i] <= 'z') {
			if (a[i + 1] >= 'A' and a[i + 1] <= 'z') {
				continue;
			}
			else cnt++;
		}
	}
	cout << cnt;
}