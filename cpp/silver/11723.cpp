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

int num;
int arr[20];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> num;
	for (int i = 0; i < num; i++) {
		string a;
		int b;
		cin >> a;
		if (a == "add") {
			cin >> b;
			arr[b - 1] = true;
		}
		else if (a == "remove") {
			cin >> b;
			arr[b - 1] = false;
		}
		else if (a == "check") {
			cin >> b;
			if (arr[b - 1] == 1) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (a == "toggle") {
			cin >> b;
			if (arr[b - 1] == 0) arr[b - 1] = 1;
			else arr[b - 1] = 0;
		}
		else if (a == "all") {
			for (int j = 0; j < 20; j++) arr[j] = 1;
		}
		else if (a == "empty") {
			fill_n(arr, 20, 0);
		}
	}
}