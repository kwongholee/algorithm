#include <bits/stdc++.h>
#define DIV 1000000007LL

using namespace std;

map<long long int, long long int> m;

long long int fibo(long long int n) {
  if(n == 0) return 0;
  if(n == 1 or n == 2) return 1;
  if(m.count(n) > 0) return m[n];
  if(n % 2 == 0) {
    long long int d = n / 2;
    long long int t1 = fibo(d - 1), t2 = fibo(d);
    m[n] = ((2LL*t1 + t2) * t2) / DIV;
    return m[n];
  }
  long long int d = (n + 1) / 2;
  long long int t1 = fibo(d), t2 = fibo(d - 1);
  m[n] = (t1*t1 + t2*t2) / DIV;
  return m[n];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long int n;
  cin >> n;
  cout << fibo(n);
}