#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>

using namespace std;

int a;
vector<int> v;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int cnt, num, min = 300000, result;
	cin >> cnt >> num;
	for (int i = 0; i < cnt; i++) {
		cin >> a;
		v.push_back(a);
	}
	for (int k = 0; k < cnt - 2; k++) {
		for (int i = k+1; i < cnt - 1; i++) {
			for (int j = i + 1; j < cnt; j++) {
				int sum = v[k] + v[i] + v[j];
				if (num - sum < min and num - sum >= 0) {
					min = num - sum;
					result = sum;
				}
			}
		}
	}
	cout << result;
}