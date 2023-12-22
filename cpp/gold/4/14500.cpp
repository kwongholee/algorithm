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

using namespace std;

int N, M, value = 0;
int table[500][500], push_x[4] = { -1,0,1,0 }, push_y[4] = { 0,-1,0,1 };
bool visited[500][500] = { false };

void findOne(int y, int x) {
    if (y + 1 < N && x + 2 < M) value = max(value, table[y][x] + table[y][x + 1] + table[y][x + 2] + table[y + 1][x + 1]);
    if (y + 2 < N && x + 1 < M) value = max(value, table[y][x] + table[y + 1][x] + table[y + 1][x + 1] + table[y + 2][x]);
    if (y - 1 >= 0 && x + 2 < M) value = max(value, table [y] [x] + table[y][x + 1] + table[y][x + 2] + table[y - 1][x + 1]);
    if (y + 2 < N && x - 1 >= 0) value = max(value, table[y][x] + table[y + 1][x] + table[y + 1][x - 1] + table[y + 2][x]);
}

void findTwo(int L, int n, int y, int x) {
  if(L == 3) {
    value = max(value, n);
    return;
  }
  for(int i = 0; i < 4; i++) {
    int new_y = y + push_y[i], new_x = x + push_x[i];
    if(new_y < 0 or new_y >= N or new_x < 0 or new_x >= M or visited[new_y][new_x]) continue;
    visited[new_y][new_x] = true;
    findTwo(L+1, n + table[new_y][new_x], new_y, new_x);
    visited[new_y][new_x] = false;
  }
}

void Find(int y, int x) {
  findOne(y, x); 
  visited[y][x] = true;
  findTwo(0, table[y][x], y, x);
  visited[y][x] = false;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M;
    for(int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j++) cin >> table[i][j];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) Find(i, j);
    }
    cout << value;
}