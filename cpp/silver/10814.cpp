#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

int num;
vector<pair<int, string>> v;

bool comp(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> num;
	for (int i = 0; i < num; i++) {
		int a;
		string b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	stable_sort(v.begin(), v.end(), comp);
	for (auto e : v) {
		cout << e.first << " " << e.second << '\n';
	}
}