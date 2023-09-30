#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    int cnt = 0;

    cin >> n;

    for (int i = 5; i <= n; i *= 5)
    {
        cnt += (n / i);
    }
    cout << cnt;
    return 0;
}