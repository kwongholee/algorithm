#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int t;
    int n, m;
    cin >> t;
    long long answer = 1;
    for (int i = 0; i < t; i++) {
        answer = 1;
        cin >> n >> m;
        if (n > (m / 2)) n = (m - n);
        for (int j = 0; j < n; j++) {
            answer *= (m - j);
        }
        for (int k = 0; k < n; k++) {
            answer /= (k + 1);
        }
        cout << answer << endl;;
    }
    return 0;
}