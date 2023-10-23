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

long long N;
int L, idx, result[100] = {-1};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> L;
	while (L <= 100) {
		if (L % 2 == 0 and N % L == L / 2) {
			result[0] = N / L - L / 2 + 1;
			break;
		}
		else if (L % 2 == 1 and N % L == 0) {
			result[0] = N / L - L / 2;
			break;
		}
		L++;
	}
	if (result[0] < 0) cout << -1;
	else {
		cout << result[0] << " ";
		for (int i = 1; i < L; i++) {
			result[i] = result[i - 1] + 1;
			cout << result[i] << " ";
		}
	}
}