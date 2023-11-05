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

string A, B;
char alpha_A[50], alpha_B[50];

int find_min(int i, int size) {
	int cnt = 0;
	for (int k = i; k < i + size; k++) {
		if (alpha_A[k - i] != alpha_B[k]) cnt++;
	}
	return cnt;
}

int main() {
	cin.tie(NULL);
	std::cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> A >> B;
	for (int i = 0; i < A.length(); i++) alpha_A[i] = A[i];
	for (int i = 0; i < B.length(); i++) alpha_B[i] = B[i];
	int min_val = 99999;
	for (int i = 0; i <= B.length() - A.length(); i++) min_val = min(min_val, find_min(i, A.length()));
	cout << min_val;
}