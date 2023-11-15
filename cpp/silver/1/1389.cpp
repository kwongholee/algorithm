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

int N, M, cnt = 99999, idx = -1;
int input[101][101];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		input[a][b] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (input[i][j] == 1) input[j][i] = 1;
			else input[i][j] = 999;
		}
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				input[i][j] = min(input[i][j], input[i][k] + input[k][j]);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		int count = 0;
		for (int j = 1; j <= N; j++) {
			if(i != j) count += input[i][j];
		}
		if (count < cnt) {
			cnt = count;
			idx = i;
		}
	}
	cout << idx;
}