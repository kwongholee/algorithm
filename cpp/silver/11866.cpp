#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

vector<int> v, result;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k, idx = 0;
	cin >> n >> k;
	if (n == 1 and k == 1) cout << "<" << 1 << ">";
	else {
		for (int i = 1; i <= n; i++) v.push_back(i);
		for (int j = 0; j < n; j++) {
			idx += (k - 1);
			while (idx > v.size() - 1) idx -= v.size();
			result.push_back(v[idx]);
			v.erase(v.begin() + idx);
		}
		for (int i = 0; i < result.size(); i++) {
			if (i == 0) cout << "<" << result[i] << ", ";
			else if (i == result.size() - 1) cout << result[i] << ">";
			else cout << result[i] << ", ";
		}
	}
}