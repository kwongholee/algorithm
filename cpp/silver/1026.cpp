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

int N, total = 0;
vector<int> A, B;

bool comp(int a, int b) {
	return a > b;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < 2; i++) {
		if (i == 0) for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			A.push_back(a);
		}
		else for (int j = 0; j < N; j++) {
			int b;
			cin >> b;
			B.push_back(b);
		}
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), comp);
	for (int i = 0; i < N; i++) {
		total += A[i] * B[i];
	}
	cout << total;
}