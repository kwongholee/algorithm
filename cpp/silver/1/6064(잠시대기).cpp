#include <bits/stdc++.h>

using namespace std;

int T, M, N, x, y;

int find(int x, int y) {
  int cnt = 1, a = 1, b = 1;
  while(true) {
    if(a == x and b == y) return cnt;
    else if (a == M and b == N) return -1;
    else {
      if(a < M) a++;
      else if(a == M) a = 1;
      if(b < N) b++;
      else if(b == N) b = 1;
      cnt++;
    }
  }
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> T;
  for(int i = 0; i < T; i++) {
    cin >> M >> N >> x >> y;
    cout << find(x,y) << '\n';
  }
}