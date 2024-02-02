#include <iostream>
#include <vector>

using namespace std;

int N;
long long B;
long long table[5][5], tmp[5][5], answer[5][5];

void Matrix_multi(long long x[5][5], long long y[5][5]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmp[i][j] = 0;
			for (int k = 0; k < N; k++) tmp[i][j] += (x[i][k] * y[k][j]);
			tmp[i][j] %= 1000;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) x[i][j] = tmp[i][j];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> table[i][j];
		answer[i][i] = 1;
	}
	while (B > 0) {
		if (B % 2 == 1) Matrix_multi(answer, table);
		Matrix_multi(table, table);
		B /= 2;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cout << answer[i][j] << " ";
		cout << '\n';
	}
}