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

int N, K;
int input[10];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	int total = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (K / input[i] > 0) {
			total += (K / input[i]);
			K -= (K / input[i]) * input[i];
		}
		if (K == 0) break;
	}
	cout << total;
}