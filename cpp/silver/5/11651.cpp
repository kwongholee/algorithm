#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <set>

using namespace std;

int num,a,b;
vector <pair<int,int>> v;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end(), comp);
	for (auto e : v) {
		cout << e.first << " " << e.second << '\n';
	}
}