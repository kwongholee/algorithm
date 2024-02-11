#include <iostream>

using namespace std;

int N, M, cnt = 987654321;
int table[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> table[i];
	int start = 0, end = 0, sum = 0;
	while (start <= end) {
		if (sum >= M) {
			cnt = min(cnt, end - start);
			sum -= table[start++];
		}
		else if (end == N) break;
		else sum += table[end++];
	}
	if (cnt == 987654321) cout << 0;
	else cout << cnt;
}