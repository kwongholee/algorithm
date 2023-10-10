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

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, B, min_time = 0x7f7f7f7f, height;
	int block[500][500];

	cin >> N >> M >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> block[i][j];
		}
	}
	for (int k = 0; k <= 256; k++) {
		int necessary_block = 0, holding_block = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int h = block[i][j] - k;
				if (h > 0) holding_block += h;
				else if (h < 0) necessary_block -= h;
			}
		}
		if (holding_block + B >= necessary_block) {
			int result = holding_block * 2 + necessary_block;
			if (min_time >= result) {
				min_time = result;
				height = k;
			}
		}
	}
	cout << min_time << " " << height;
}