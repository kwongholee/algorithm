#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

int N, K;
vector<int> v, result;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	int k = 0;
	for (int i = 1; i <= N; i++) v.push_back(i);
	while (!v.empty()) {
		k += K - 1;
		while (k >= v.size()) k -= v.size();
		result.push_back(v[k]);
		v.erase(v.begin() + k);
	}
	cout << "<";
	for (int i = 0; i < N; i++) {
		if (i == N - 1) cout << result[i] << ">";
		else cout << result[i] << ", ";
	}
}