#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int total = 0;
	vector<int> score, idx;
	for (int i = 0; i < 8; i++) {
		int num;
		cin >> num;
		score.push_back(num);
	}
	vector<int> copy = score;
	sort(score.begin(), score.end());
	for (int i = 7; i > 2; i--) {
		total += score[i];
		idx.push_back(find(copy.begin(), copy.end(), score[i]) - copy.begin() + 1);
	}
	sort(idx.begin(), idx.end());
	cout << total << '\n';
	for (auto e : idx) cout << e << ' ';
}