#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		if(v.end() == find(v.begin(), v.end(), a)) {}
		else v.push_back(a);
	}
}