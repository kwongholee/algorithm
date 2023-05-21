#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, total = 0;
	cin >> a;
	string b;
	cin >> b;
	vector<char> v;
	for (int i = 0; i < a; i++) v.push_back(b[i]-'0');
	for (auto e : v) total += e;
	cout << total;
}