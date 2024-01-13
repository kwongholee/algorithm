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

using namespace std;

int R, C, value = 0;
char table[21][21];
int push_a[4] = { 1,0,-1,0 }, push_b[4] = { 0,1,0,-1 };
bool visited[26];

void dfs(int a, int b, int n) {
	int alpha = table[a][b] - 'A';
	visited[alpha] = true;
	for (int i = 0; i < 4; i++) {
		int new_a = a + push_a[i], new_b = b + push_b[i], new_alpha = table[new_a][new_b] - 'A';
		if (!visited[new_alpha] and 1 <= new_a and new_a <= R and 1 <= new_b and new_b <= C) dfs(new_a, new_b, n + 1);
	}
	value = max(value, n);
	visited[alpha] = false;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) cin >> table[i][j];
	}
	dfs(1, 1, 1);
	cout << value;
}