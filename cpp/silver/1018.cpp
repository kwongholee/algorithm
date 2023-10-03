#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

int m, n, minValue = 50000;
string input[50];
string WB[8] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};
string BW[8] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

int WB_check(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (input[x + i][y + j] != WB[i][j]) cnt++;
		}
	}
	return cnt;
}
int BW_check(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (input[x + i][y + j] != BW[i][j]) cnt++;
		}
	}
	return cnt;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		cin >> input[i];
	}
	for (int i = 0; i + 8 <= m; i++) {
		for (int j = 0; j + 8 <= n; j++) {
			int temp;
			temp = min(BW_check(i, j), WB_check(i, j));
			if (temp < minValue) minValue = temp;
		}
	}
	cout << minValue;
}