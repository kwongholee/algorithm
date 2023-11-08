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

int n;
int input[50];
bool visited[50] = { false };
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	cin.tie(NULL);
	std::cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
		pq.push(input[i]);
	}
	int cnt = 0;
	while (!pq.empty()) {
		int x = pq.top();
		for (int i = 0; i < n; i++) {
			if (input[i] == x and !visited[i]) {
				input[i] = cnt;
				visited[i] = true;
				break;
			}
		}
		cnt++;
		pq.pop();
	}
	for (int i = 0; i < n; i++) cout << input[i] << " ";
}