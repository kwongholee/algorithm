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

int table[10], max_i = 0, six_nine = 0;
string N;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N.size(); i++) {
		table[N[i] - '0']++;
	}
	for (int i = 0; i < 10; i++) {
		if (i == 6 or i == 9) six_nine += table[i];
		else if (max_i < table[i]) max_i = table[i];
	}
	if (six_nine % 2 == 0 and six_nine / 2 >= max_i) cout << six_nine / 2;
	else if (six_nine % 2 == 1 and six_nine / 2 + 1 >= max_i) cout << six_nine / 2 + 1;
	else cout << max_i;
}