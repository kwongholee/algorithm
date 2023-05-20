#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a;
	cin >> a;
	vector<int> v;
	vector<double> v1;
	int max = 0;
	double total = 0, average;
	for (int i = 0; i < a; i++) {
		int b;
		cin >> b;
		v.push_back(b);
		if (max < b) max = b;
	}
	for (auto e : v) {
		double a;
		a = (double)e / max * 100;
		total += a;
		v1.push_back(a);
	}
	average = (double)(total / a);
	cout << average;
}