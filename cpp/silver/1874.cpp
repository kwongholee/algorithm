#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>

using namespace std;

int n, stack_num = 0;
stack<int> s;
vector<char> result;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	s.push(stack_num);
	stack_num++;
	
	bool valid = true;
	int num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		while (num > s.top()) {
			s.push(stack_num);
			stack_num++;
			result.push_back('+');
		}
		if (num == s.top()) {
			s.pop();
			result.push_back('-');
		}
		else {
			valid = false;
		}
	}
	if (valid) for (auto e : result) cout << e << '\n';
	else cout << "NO";
}