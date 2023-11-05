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

int N, blue = 0, white = 0;
int input[128][128];

void paper(int N, int start_x, int start_y) {
	int in_blue = 0, in_white = 0;
	while (in_blue == 0 or in_white == 0) {
		for (int i = start_x; i < start_x + N; i++) {
			for (int j = start_y; j < start_y + N; j++) {
				if (input[i][j] == 1) in_blue++;
				else in_white++;
			}
		}
		break;
	}
	if (in_blue == 0 and in_white > 0) white += 1;
	else if (in_white == 0 and in_blue > 0) blue += 1;
	else {
		paper(N / 2, start_x, start_y);
		paper(N / 2, start_x + N/2, start_y);
		paper(N / 2, start_x, start_y + N/2);
		paper(N / 2, start_x + N/2, start_y + N/2);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input[i][j];
		}
	}
	paper(N, 0, 0);
	cout << white << '\n';
	cout << blue;
}