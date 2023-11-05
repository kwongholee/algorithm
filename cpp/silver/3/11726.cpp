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

int n;
int arr[1000] = { 1,2 };

int main() {
	cin.tie(NULL);
	std::cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 2; i < n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	}
	cout << arr[n-1];
}