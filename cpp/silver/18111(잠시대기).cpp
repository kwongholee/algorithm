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

int N, M;
long long B;
int height[257];
vector<int> v;

pair<int,int> minecraft(int most, int less) {
	int j = most, value = 999999, value_idx;
	long long holding_block = 0, necessary_block = 0;
	while (j >= less) {
		int result = 0;
		for (int i = 0; i < 257; i++) {
			if (height[i] != 0 and i < j) {
				result += (j - i) * height[i];
				necessary_block += (j - i) * height[i];
			}
			else if (height[i] != 0 and i > j) {
				result += (i - j) * height[i] * 2;
				holding_block += (i - j) * height[i];
			}
		}
		if (holding_block + B >= necessary_block) {
			if (value > result) {
				value = result;
				value_idx = j;
			}
		}
		j--;
	}
	return { value, value_idx };
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> B;
	for (int i = 0; i < N * M; i++) {
		int a;
		cin >> a;
		height[a]++;
	}
	int most = 0, less = 256;
	for (int i = 256; i >= 0; i--) {
		if (height[i] > 0) {
			if (i < less)less = i;
			else if (i > most) most = i;
		}
	}
	cout << minecraft(most, less).first << " " << minecraft(most, less).second;
}