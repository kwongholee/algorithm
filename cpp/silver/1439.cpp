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
#include <cstring>

using namespace std;

string s;
int zero = 0, one = 0;
bool type = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if(i == 0) {
			type = s[i] - '0';
			if (s[i] - '0' == 0) zero++;
			else one++;
		}
		else {
			if (type == s[i] - '0') continue;
			else {
				type = s[i] - '0';
				if (s[i] - '0' == 0) zero++;
				else one++;
			}
		}
	}
	if (zero > one) cout << one;
	else cout << zero;
}