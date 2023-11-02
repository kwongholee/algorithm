#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstring>

using namespace std;

int N, M, push[4] = { 1,0, -1, 0 };
char input[100][100], now;
map<char, int> m = { {'W', 0}, {'B', 0} };

int dfs(int a, int b) {
	if (a < 0 or a >= M or b < 0 or b >= N or input[a][b] != now) return 0;
	int cnt = 1;
	input[a][b] = 'N';
	for (int i = 0; i < 4; i++) {
		cnt += dfs(a + push[i], b + push[3 - i]);
	}
	return cnt;
}

int main() {
	cin.tie(NULL);
	std::cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) input[i][j] = s[j];
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (input[i][j] != 'N') {
				now = input[i][j];
				m[now] += pow(dfs(i, j), 2);
			}
		}
	}
	cout << m['W'] << " " << m['B'];
}