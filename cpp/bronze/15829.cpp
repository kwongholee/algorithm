#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <set>

using namespace std;

int length;
string s;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> length >> s;
	long long hash = 0, r = 1, M = 1234567891;
	for (int i = 0; i < length; i++) {
		hash = (hash + (s[i] - 96) * r) % M;
		r = (r * 31) % M;
	}
	cout << hash;
}