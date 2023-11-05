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
vector<int> v;

int factorial(int a) {
	int result = 1;
	for (int i = 1; i <= a; i++) result *= i;
	return result;
}

int combination(int a, int b, int c) {
	return factorial(a + b + c) / (factorial(a) * factorial(b) * factorial(c));
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	for (auto e : v) {
		int result = 0, one, two, three;
		for (int i = 0; 3 * i <= e; i++) {
			three = i;
			for (int j = 0; 2 * j <= e - 3 * i; j++) {
				one = e - 3 * i - 2 * j;
				two = j;
				result += combination(one, two, three);
			}
		}
		cout << result << '\n';
	}
}