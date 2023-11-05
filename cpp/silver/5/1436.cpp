#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <set>

using namespace std;

int num;

int func(int num) {
	
	int target = 666, cnt = 0;
	while (true) {
		string n = to_string(target);
		for (int i = 0; i < n.length()-2; i++) {
			if (n[i] == '6' and n[i + 1] == '6' and n[i + 2] == '6') {
				cnt++;
				if (cnt == num) return target;
				break;
			}
		}
		target++;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> num;
	cout << func(num);
}