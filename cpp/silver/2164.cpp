#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

queue<int> v;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num;
	cin >> num;
	for (int i = 1; i <= num; i++) v.push(i);
	while (v.size() != 1) {
		v.pop();
		v.push(v.front());
		v.pop();
	}
	cout << v.front();
}