#include <iostream>

using namespace std;

string S, p, t = "";

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> S >> p;
	int n = S.size(), m = p.size();
	for (int i = 0; i < n; i++) {
		t += S[i];
		if (t.length() >= m) {
			bool flag = true;
			for (int j = 0; j < m; j++) {
				if (t[t.length() - m + j] != p[j]) {
					flag = false;
					break;
				}
			}
			if (flag) t.erase(t.end() - m, t.end());
		}
	}
	if (t.empty()) cout << "FRULA";
	else cout << t;
}