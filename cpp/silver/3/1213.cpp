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

string s;
char target;
int okay = 0, s_size;
map<char, int> m;
char table[50];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> s;
	s_size = s.size();
	for (int i = 0; i < s_size; i++) m[s[i]]++;
	for (auto e : m) {
		if (e.second % 2 ==  1) {
			target = e.first;
			okay++;
		}
	}
	if (okay <= 1) {
		if (okay == 0) {
			int k = 0;
			for (auto e : m) {
				for (int i = 0; i < e.second / 2; i++) {
					table[k] = e.first;
					table[s_size - k - 1] = e.first;
					k++;
				}
			}
		}
		else if (okay == 1) {
			int k = 0;
			for (auto e : m) {
				if (e.first != target) {
					for (int i = 0; i < e.second / 2; i++) {
						table[k] = e.first;
						table[s_size - k - 1] = e.first;
						k++;
					}
				}
				else {
					for (int i = e.second/ 2; i >= 1; i--) {
						table[k] = e.first;
						table[s_size - k - 1] = e.first;
						k++;
					}
					table[s_size / 2] = target;
				}
			}
		}
		string s = "";
		for (int i = 0; i < s_size; i++) s += table[i];
		cout << s;
	}
	else {
		cout << "I'm Sorry Hansoo";
	}
}