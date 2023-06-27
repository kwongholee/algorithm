#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a;
	int b;
	cin >> a >> b;
	cout << a[b-1];
}