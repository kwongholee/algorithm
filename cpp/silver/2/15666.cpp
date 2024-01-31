#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int table[10], check[10], arr[10];

void dfs(int d, int i) {
	if (d == m) {
		for (int j = 0; j < m; j++) cout << arr[j] << " ";
		cout << '\n';
		return;
	}
	for (int j = i; j < n; j++) {
		arr[d] = table[j];
		dfs(d + 1, j);
		while (table[j] == table[j + 1]) j++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> table[i];
	sort(table, table + n);
	dfs(0, 0);
}