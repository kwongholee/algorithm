#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(NULL);
	ios_base::sync_with_stdio(false);

  int num;
  cin >> num;
  vector<int> time, price;
  for(int i = 0; i < num; i++) {
    int a, b;
    cin >> a >> b;
    time.push_back(a);
    price.push_back(b);
  }
  for(int i = 0; i < num; i++) {
    if(time[i] + (i+1) > (num)) {
      time.erase(time.begin() + i);
      price.erase(price.begin() + i);
    }
  }
}