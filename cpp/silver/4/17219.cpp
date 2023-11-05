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
pair<string, string> input[100000];

string binsearch(string b) {
	int low = 0, high = 100000;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (input[mid].first == b) return input[mid].second;
		else if (input[mid].first > b) high = mid - 1;
		else low = mid + 1;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> input[i].first >> input[i].second;
	sort(input, input + 100000);
	for (int i = 0; i < M; i++) {
		string a;
		cin >> a;
		cout << binsearch(a) << '\n';
	}
}