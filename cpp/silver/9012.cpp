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

string check_VPS(string e) {
	int cnt = 0;
	for (int i = 0; i < e.size(); i++) {
		if (e[i] == '(') cnt++;
		else cnt--;
		if (cnt < 0) break;
	}
	if (cnt == 0) return "YES";
	else return "NO";
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> num;
	for (int i = 0; i < num; i++) {
		string a;
		cin >> a;
		v.push_back(a);
	}
	for (auto e : v) {
		cout << check_VPS(e) << '\n';
	}
}