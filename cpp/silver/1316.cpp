#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		vector<char> v;
		if (a.length() == 1) cnt++;
		else {
			for (int j = 0; j < a.length() - 1; j++) {
				if (a[j] != a[j + 1]) {
					if (v.end() == find(v.begin(), v.end(), a[j])) {
						v.push_back(a[j]);
					}
					else {
						break;
					}
				}
				if (j == a.length() - 2) {
					if (v.end() == find(v.begin(), v.end(), a[j + 1])) {
						cnt++;
					}
				};
			}
		}
	}
	cout << cnt;
}