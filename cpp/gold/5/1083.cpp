#include <bits/stdc++.h>

using namespace std;

int N, S, idx = 0, cnt = 0;
vector<int> v(N,0);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
  for(int i = 0; i < N; i++) cin >> v[i];
  cin >> S;
  for (int i = 0; i < N; i++) {
		int max = v[i];
		int maxi = i;
		for (int j = i + 1; j < N; j++) {
			if (S - (j - i) >= 0) {
				if (max < v[j]) {
					max = v[j];
					maxi = j;
				}
			}
		}
		for (int j = maxi; j > i; j--) swap(v[j], v[j - 1]);
		S -= (maxi - i);
		if (S <= 0) break;
	}
  for(int i = 0; i < N; i++) cout << v[i] << " ";
}