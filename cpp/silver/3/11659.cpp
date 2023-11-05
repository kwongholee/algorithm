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
int input[100000], table[100000];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	for (int i = 0; i < 100000; i++) {
		if (i == 0) table[i] = input[i];
		else table[i] = table[i - 1] + input[i];
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << table[b - 1] - table[a - 2] << '\n';
	}
}