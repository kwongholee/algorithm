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

int N, input[1000000];
set<int> s;
map<int, int> m;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
		s.insert(input[i]);
	}
	int k = 0;
	for (auto e : s) {
		m.insert({ e,k });
		k++;
	}
	for (int i = 0; i < N; i++) cout << m[input[i]] << " ";
}