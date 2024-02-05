#include <iostream>

using namespace std;

int N, result = 0;
int table[1001], dp1[1001], dp2[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> table[i];
	fill_n(dp1, 1001, 1);
	fill_n(dp2, 1001, 1);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (table[i] > table[j]) dp1[i] = max(dp1[i], dp1[j] + 1);
		}
	}
	for (int i = N; i > 0; i--) {
		for (int j = N; j > i; j--) {
			if (table[i] > table[j]) dp2[i] = max(dp2[i], dp2[j] + 1);
		}
	}
	for (int i = 1; i <= N; i++) {
		if (dp1[i] + dp2[i] - 1 > result) result = dp1[i] + dp2[i] - 1;
	}
	cout << result;
}