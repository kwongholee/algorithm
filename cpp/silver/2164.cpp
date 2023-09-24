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
	vector<int> v;
	for (int i = 1; i <= num; i++) v.push_back(i);
	while (true) {
		if (v.size() == 1) break;
		else {	
			v.erase(v.begin() + 0);
			v.push_back(v[0]);
			v.erase(v.begin() + 0);
		}
	}
	cout << v[0];
}