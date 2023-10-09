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

int num, total = 0, most = -4001, double_check = 1, most_value;
int input[8001];
vector<int> v;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> num;
	for (int i = 0; i < num; i++) {
		int a;
		cin >> a;
		v.push_back(a);
		total += a;
		input[a + 4000]++;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < 8001; i++) {
		if (input[i] == 0) continue;
		if (input[i] == most) {
			if (double_check) {
				most_value = i - 4000;
				double_check = 0;
			}
		}
		if (input[i] > most) {
			most_value = i - 4000;
			double_check = 1;
			most = input[i];
		}
	}
	cout << floor((double)total / (double)num + 0.5) << '\n' << v[num / 2] << '\n' << most_value << '\n' << v.back() - v.front();
}