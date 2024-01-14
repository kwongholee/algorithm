#include <bits/stdc++.h>

using namespace std;

int T, N;
int table[2][100001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> T;
  for(int k = 0; k < T; k++) {
    cin >> N;
    for(int j = 0; j < 2; j++) {
      for(int i = 1; i <= N; i++) cin >> table[j][i];
    }
    for(int i = 2; i <= N; i++) {
      table[0][i] = max(table[1][i-2], table[1][i-1]) + table[0][i];
      table[1][i] = max(table[0][i-2], table[0][i-1]) + table[1][i];
    }
    cout << max(table[0][N], table[1][N]) << '\n';
  }
}