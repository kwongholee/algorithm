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

string T;
priority_queue<string, vector<string>, greater<string>> min_T;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> T;
	for (int i = 0; i < T.length() - 2; i++) {
		for (int j = i + 1; j < T.length() - 1; j++) {
			for (int k = j + 1; k < T.length(); k++) {
				string copy = T;
				reverse(copy.begin(), copy.begin() + j);
				reverse(copy.begin() + j, copy.begin() + k);
				reverse(copy.begin() + k, copy.end());
				min_T.push(copy);
			}
		}
	}
	cout << min_T.top();
}