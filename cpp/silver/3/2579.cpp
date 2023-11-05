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

int N;
int input[301], table[301];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> input[i];
	table[1] = input[1];
	table[2] = input[1] + input[2];
	table[3] = max(input[1] + input[3], input[2] + input[3]);
	for (int i = 3; i <= N; i++) table[i] = max(input[i] + table[i - 2], input[i] + input[i - 1] + table[i - 3]);
	cout << table[N];
}