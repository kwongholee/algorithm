#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	float total = 0, score = 0;
	vector <float> num;
	vector<string> str;
	for (int i = 0; i < 20; i++) {
		string a, c;
		float b;
		cin >> a >> b >> c;
		num.push_back(b);
		str.push_back(c);
	}
	for (int i = 0; i < 20; i++) {
		if (str[i][0] != 'P') {
			total += num[i];
			if (str[i][0] == 'A') {
				if (str[i][1] == '+') {
					score += num[i] * 4.5;
				}
				else {
					score += num[i] * 4.0;
				}
			}
			else if (str[i][0] == 'B') {
				if (str[i][1] == '+') {
					score += num[i] * 3.5;
				}
				else {
					score += num[i] * 3.0;
				}
			}
			else if (str[i][0] == 'C') {
				if (str[i][1] == '+') {
					score += num[i] * 2.5;
				}
				else {
					score += num[i] * 2.0;
				}
			}
			else if (str[i][0] == 'D') {
				if (str[i][1] == '+') {
					score += num[i] * 1.5;
				}
				else {
					score += num[i] * 1.0;
				}
			}
		}
	}
	cout << score / total;
}