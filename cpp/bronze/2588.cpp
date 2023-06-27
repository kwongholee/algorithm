#include <iostream>

using namespace std;

int main() {
	int a,b;
	cin >> a >> b;
	int c = a * (b % 10);
	int d = a * ((b / 10) % 10);
	int e = a * (b / 100);
	int f = 100 * e + 10 * d + c;
	cout << c << endl;
	cout << d << endl;
	cout << e << endl;
	cout << f << endl;
}