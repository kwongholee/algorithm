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

int N, r, c;

int square_num(int r, int c, int N) {
	int i, result = 0, sq_size = N;
	while (sq_size >= 1) {
		if (r < pow(2, sq_size - 1) and c < pow(2, sq_size - 1)) i = 0;
		else if (r < pow(2, sq_size - 1) and c >= pow(2, sq_size - 1)) {
			i = 1;
			c -= pow(2, sq_size - 1);
		}
		else if (r >= pow(2, sq_size - 1) and c < pow(2, sq_size - 1)) {
			i = 2;
			r -= pow(2, sq_size - 1);
		}
		else {
			i = 3;
			r -= pow(2, sq_size - 1);
			c -= pow(2, sq_size - 1);
		}
		result += pow(2, (2 * sq_size - 2)) * i;
		sq_size--;
	}
	return result;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> r >> c;
	cout << square_num(r, c, N);
}