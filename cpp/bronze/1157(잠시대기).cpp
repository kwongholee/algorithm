#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> num, idx;
	vector<char> v;
	string s;
	cin >> s;
	if (s.length() == 1) {
		if (s[0] >= 'a' and s[0] <= 'z') {
			s[0] -= 32;
		}
		cout << s;
	}
	else {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] >= 'a' and s[i] <= 'z') {
				s[i] -= 32;
			}
			if (v.end() == find(v.begin(), v.end(), s[i])) {
				v.push_back(s[i]);
				num.push_back(1);
				idx.push_back(i);
			}
			else {
				num[find(v.begin(), v.end(), s[i]) - v.begin()] += 1;
			}
		}
		vector<int> copy(num);
		sort(copy.begin(), copy.end());
		if (copy[copy.size() - 1] == copy[copy.size() - 2]) {
			cout << "?";
		}
		else {
			cout << v[idx[find(num.begin(), num.end(), copy[copy.size() - 1]) - num.begin()]];
		}
	}
}