#include <iostream>

using namespace std;

int main() {
	int totalPrice, totalNum, result = 0;
	cin >> totalPrice >> totalNum;
	for (int i = 0; i < totalNum; i++) {
		int price, num;
		cin >> price >> num;
		result += price * num;
	}
	if (totalPrice == result) cout << "Yes";
	else cout << "No";
}