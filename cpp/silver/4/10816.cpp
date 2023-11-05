#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

int n, m, num;
vector<int> v;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		cout << upper_bound(v.begin(), v.end(), num) - lower_bound(v.begin(), v.end(), num) << " ";
	}
}