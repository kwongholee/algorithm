#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <set>

using namespace std;

int a,b,v;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> a >> b >> v;
	if ((v - a) % (a - b) == 0) cout << ((v - a) / (a - b)) + 1;
	else cout << ((v - a) / (a - b)) + 2;
}