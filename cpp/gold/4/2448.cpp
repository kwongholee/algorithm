#include <iostream>
#include <string.h>

using namespace std;

int N;
char table[3100][6200];

void star(int y, int x, int n) {
	if (n == 3) {
		table[y][x] = '*';
		table[y + 1][x - 1] = '*';
		table[y + 1][x + 1] = '*';

		for (int i = 0; i < 5; i++) table[y + 2][x - 2 + i] = '*';
	}
	else {
		star(y, x, n / 2);
		star(y + n / 2, x - n / 2, n / 2);
		star(y + n / 2, x + n / 2, n / 2);
	}
}

void solution() {
	memset(table, ' ', sizeof(table));
	star(0, N - 1, N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) cout << table[i][j];
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	solution();
}