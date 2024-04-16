#include <iostream>

using namespace std;

int N, M;
int arr[2001], check[2001][2001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
	for (int i = 1; i <= N - 1; i++) {
		if (arr[i] == arr[i + 1]) check[i][i + 1] = true;
	}
	for (int i = 1; i <= N; i++) {
		check[i][i] = true;
	}
	for (int i = N - 1; i >= 1; i--) {
		for (int j = i + 2; j <= N; j++) {
			if (arr[i] == arr[j] && check[i + 1][j - 1] == true) {
				check[i][j] = true;
			}
		}
	}
	int m, s, e;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		cout << check[s][e] << '\n';
	}
}