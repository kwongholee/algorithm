#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

string S;
stack<char> st;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> S;
	for (int i = 0; i < S.length(); i++) {
		if ('A' <= S[i] and S[i] <= 'Z') {
			cout << S[i];
			continue;
		}
		if (S[i] == '(') st.push(S[i]);
		else if (S[i] == ')') {
			while (!st.empty() and st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.pop();
		}
		else if (S[i] == '*' or S[i] == '/') {
			while (!st.empty() and (st.top() == '*' or st.top() == '/')) {
				cout << st.top();
				st.pop();
			}
			st.push(S[i]);
		}
		else if (S[i] == '+' or S[i] == '-') {
			while (!st.empty() and st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.push(S[i]);
		}
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}