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
int input[100][100], min_path[100][100];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		input[a - 1][b - 1] = 1;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (input[i][j] == 1) input[j][i] = 1;
			else input[i][j] == 999;
		}
	}
	int input_copy[100][100];
	copy(&input[0][0], &input[0][0] + 10000, &input_copy[0][0]);
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (input_copy[i][j] > input_copy[i][k] + input_copy[k][j]) {
					input_copy[i][j] = input_copy[i][k] + input_copy[k][j];
					min_path[i][j] = k;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << min_path[i][j] << " ";
		}
		cout << '\n';
	}
}