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

int N, M, B, most = -1, most_value = -1;
int height[257];

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
	bool check = false;
	for (int i = 0; i < 257; i++) {
		if (height[i] > most) {
			most = height[i];
			most_value = i;
			check = false;
		}
		else if (height[i] == most) check = true;
	}
	if (!check) {
		int result = 0, necessary_block = 0, holding_block = B;
		for (int i = 0; i < 257; i++) {
			if (height[i] != 0 and i < most_value) {
				result += (most - height[i]) * (most_value - i);
				necessary_block += (most - height[i]);
			}
			else if (height[i] == 0 and i > most_value) {
				result += (most - height[i]) * (i - most_value) * 2;
				holding_block += (most - height[i]) * (i - most_value);
			}
		}
		if (holding_block < necessary_block) most_value--;
	}
}