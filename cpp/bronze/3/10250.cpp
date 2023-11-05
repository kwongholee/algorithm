#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int H, W, N, cnt = 1;
		cin >> H >> W >> N;
		while (true) {
			if (N - H <= 0) break;
			else {
				N -= H;
				cnt++;
			}
		}
		if (cnt <= 9) cout << N << "0" << cnt << '\n';
		else cout << N << cnt << '\n';
	}
}