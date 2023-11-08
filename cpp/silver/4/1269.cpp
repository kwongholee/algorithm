#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstring>

using namespace std;

int A, B;
set<int> a, b, m_a, m_b;

int main() {
	cin.tie(NULL);
	std::cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> A >> B;
	for (int i = 0; i < A; i++) {
		int num;
		cin >> num;
		a.insert(num);
	}
	for (int i = 0; i < B; i++) {
		int num;
		cin >> num;
		b.insert(num);
	}
	for (auto e : a) {
		if (b.insert(e).second) m_a.insert(e);
	}
	for (auto e : b) {
		if (a.insert(e).second) m_b.insert(e);
	}
	cout << m_a.size() + m_b.size();
}