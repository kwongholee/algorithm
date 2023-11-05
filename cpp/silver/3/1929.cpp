#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <set>

using namespace std;

int a, b;
vector<int> v;

bool isFunc(int a) {
	if (a == 1) return false;
	else {
		for (int i = 2; i * i <= a; i++) {
			if (a % i == 0) return false;
		}
		return true;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> a >> b;
	for (int i = a; i <= b; i++) {
		if (isFunc(i)) v.push_back(i);
	}
	for (auto e : v) cout << e << '\n';
}