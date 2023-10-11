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

int num, parsing_num;
long long input[10000], final;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> num >> parsing_num;
	long long maxI = 0;
	for (int i = 0; i < num; i++) {
		cin >> input[i];
		maxI = max(maxI, input[i]);
	}
	long long left = 1, right = maxI, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		long long result = 0;
		for (int i = 0; i < num; i++) {
			result += input[i] / mid;
		}
		if (result >= parsing_num) {
			left = mid + 1;
			final = max(final, mid);
		}
		else right = mid - 1;
	}
	cout << final;
}