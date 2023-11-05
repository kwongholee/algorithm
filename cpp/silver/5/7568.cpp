#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <set>

using namespace std;

int num;
pair<int, int> person[50];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int rank = 1;
	cin >> num;
	for (int i = 0; i < num; i++) cin >> person[i].first >> person[i].second;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (person[i].first < person[j].first and person[i].second < person[j].second) {
				rank++;
			}
		}
		cout << rank << " ";
		rank = 1;
	}
}