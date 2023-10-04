#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

int num;
vector<string> v;

bool comp(string a, string b) {
	if (a.length() == b.length()) return a < b;
	else return a.length() < b.length();
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> num;
	for (int i = 0; i < num; i++) {
		string b;
		cin >> b;
		if (v.end() == find(v.begin(), v.end(), b)) v.push_back(b);
	}
	sort(v.begin(), v.end(), comp);
	for (auto e : v) {
		cout << e << '\n';
	}
}