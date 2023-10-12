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

string s;
int alphabet[26];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		int idx = tolower(s[i]) - 'a';
		alphabet[idx]++;
	}
	int max = 0, max_idx = -1;
	bool check = false;
	for (int i = 0; i < 26; i++) {
		if (max < alphabet[i]) {
			max = alphabet[i];
			max_idx = i;
			check = false;
		}
		else if (max == alphabet[i]) check = true;
	}
	if (check) cout << "?";
	else cout << char(toupper(max_idx + 'a'));
}