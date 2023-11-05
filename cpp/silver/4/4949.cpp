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

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		getline(cin, s);
		if (s[0] == '.') break;
		else {
			stack<char> st;
			bool result = true;
			for (int i = 0; i < s.length(); i++) {
				char c = s[i];
				if (c == '(' or c == '[') st.push(c);
				else if (c == ')') {
					if (!st.empty() and st.top() == '(') st.pop();
					else {
						result = false;
						break;
					}
				}
				else if (c == ']') {
					if (!st.empty() and st.top() == '[') st.pop();
					else {
						result = false;
						break;
					}
				}
			}
			if (result and st.empty()) cout << "yes" << '\n';
			else cout << "no" << '\n';
		}
	}
}