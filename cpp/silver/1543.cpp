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

int cnt = 0;
string a, b;

int main() {
	cin.tie(NULL);
	std::cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	getline(cin, a);
	getline(cin, b);
	
	for (int i = 0; i < a.length(); i++) {
		bool result = true;
		for (int j = 0; j < b.length(); j++) {
			if (a[i + j] != b[j]) {
				result = false;
				break;
			}
		}
		if (result) {
			cnt++;
			i += b.length() - 1;
		}
	}
	cout << cnt;
}