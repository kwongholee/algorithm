#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int result, cnt = 0, idx = 0;
	vector<int> v = { 64,32,16,8,4,2,1 };
	cin >> result;
	while (true) {
		for (int i = idx; i < 7; i++) {
			if (result - v[i] == 0) {
				result = 0;
				cnt++;
				break;
			}
			else if (i == 6) {
				result -= 1;
				cnt++;
				break;
			}
			else if (result - v[i] < 0 and result - v[i+1] > 0) {
				idx = i+1;
				result -= v[i+1];
				cnt++;
				break;
			}
		}
		if (0 == result) break;
	}
	cout << cnt;
}