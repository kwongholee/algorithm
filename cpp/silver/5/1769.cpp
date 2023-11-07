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

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string n;
	cin >> n;
	int num = 0, cnt = 0;
	while (n.size() != 1) {
		cnt++;
		num = 0;
		for (int i = 0; i < n.size(); i++) {
			num += n[i] - '0';
		}
		n = to_string(num);
	}
	cout << cnt << '\n';
	if (n == "3" or n == "6" or n == "9") cout << "YES";
	else cout << "NO";
}