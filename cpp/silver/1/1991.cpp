#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v[26];

void Preorder(char c) {
  cout << c;
  int n = c - 'A';
  for(int i = 0; i < 2; i++) {
    if(v[n][i] != '.') Preorder(v[n][i]);
  }
}

void Inorder(char c) {
  int n = c - 'A';
  for(int i = 0; i < 2; i++) {
    if(v[n][i] != '.') Inorder(v[n][i]);
    if(i == 0) cout << c;
  }
}

void Postorder(char c) {
  int n = c - 'A';
  for(int i = 0; i < 2; i++) {
    if(v[n][i] != '.') Postorder(v[n][i]);
  }
  cout << c;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

  cin >> N;
  for(int i = 0; i < N; i++) {
    char a,b,c;
    cin >> a >> b >> c;
    v[a-'A'].push_back(b);
    v[a-'A'].push_back(c);
  }
  Preorder('A');
  cout << '\n';
  Inorder('A');
  cout << '\n';
  Postorder('A');
}