#include<bits/stdc++.h>
using namespace std;
int n;
int visited[1000004];
int people[100004];
int ret[1000004];

void check(int num) {
	if (num == 1) {
		return;
	}
	for (int i = 1; i * i <= num; i++) {
		if (num % i == 0) {
			if (visited[i] == 1) {
				ret[i]++;
				ret[num]--;
			}
			if (visited[num / i] == 1 && i*i!=num) {
				ret[num/i]++;
				ret[num]--;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> people[i];
		visited[people[i]] = 1;
	}
	for (int i = 0; i < n; i++) {
		check(people[i]);
	}
	for (int i = 0; i < n; i++) {
		cout << ret[people[i]] << ' ';
	}
}