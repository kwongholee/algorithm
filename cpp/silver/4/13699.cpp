#include <iostream>

using namespace std;

long long int n;
long long int arr[36] = { 1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		long long int total = 0;
		for (int j = 0; j <= i - 1; j++) total += (arr[j] * arr[i - 1 - j]);
		arr[i] = total;
	}
	cout << arr[n];
}