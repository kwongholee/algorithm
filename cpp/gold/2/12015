#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int table[1000001];
vector<int> sequence;

void binsearch(int n) {
	int low = 0, high = sequence.size() - 1, mid;
	int res = 10000000007;
	while (low <= high) {
		mid = (low + high) / 2;
		int num = sequence[mid];
		if (num >= n) {
			if (res > mid) res = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}
	sequence[res] = n;
}

void findLIS() {
	sequence.push_back(table[0]);
	for (int i = 1; i < N; i++) {
		if (sequence.back() < table[i]) sequence.push_back(table[i]);
		else binsearch(table[i]);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> table[i];
	findLIS();
	cout << sequence.size();
}
