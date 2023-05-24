#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	vector<int> v1 = { 1,1,2,2,2,8 };
	vector<int> v2;
	v2.push_back(a);
	v2.push_back(b);
	v2.push_back(c);
	v2.push_back(d);
	v2.push_back(e);
	v2.push_back(f);
	for (int i = 0; i < 6; i++) cout << v1[i] - v2[i] << " ";
}