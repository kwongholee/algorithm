#include <bits/stdc++.h>

using namespace std;

int N, M;
int input[9], arr[9];
bool visited[9];

void dfs(int num) {
  if(num == M) {
    for(int i = 0; i < M; i++) cout << arr[i] << " ";
    cout << '\n';
    return;
  }
  int last = 0;
  for(int i = 0; i < N; i++) {
    if(!visited[i] and input[i] != last) {
      arr[num] = input[i];
      last = arr[num];
      visited[i] = true;
      dfs(num+1);
      visited[i] = false;
    }
  }
  return;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
	ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for(int i = 0; i < N; i++) cin >> input[i];
  sort(input, input + N);
  dfs(0);
}