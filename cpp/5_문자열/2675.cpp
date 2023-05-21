#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a;
	cin >> a;
	vector<int> v1;
	vector<string> v2;
	for (int i = 0; i < a; i++) {
		int b;
		string c;
		cin >> b >> c;
		v1.push_back(b);
		v2.push_back(c);
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < v2[i].length(); j++) {
			for (int k = 0; k < v1[i]; k++) cout << v2[i][j];
		}
		cout << '\n';
	}
}