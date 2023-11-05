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

int N, M;
map<int, string> m1;
map<string, int> m2;

bool isNumber(const string& str) {
	return !str.empty() &&
		std::find_if(str.begin(), str.end(), [](unsigned char c) {
		return !std::isdigit(c);
			}) == str.end();
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string a;
		cin >> a;
		m1.insert({ i, a });
		m2.insert({ a,i });
	}
	for (int i = 0; i < M; i++) {
		string a;
		cin >> a;
		if (isNumber(a)) cout << m1[stoi(a)] << '\n';
		else cout << m2[a] << '\n';
	}
}