#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int dp[1002][1002];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> s1 >> s2;
  dp[0][0] = 0;
  for(int i = 0; i <= s1.size(); i++) dp[i][0] = 0; 
  for(int i = 0; i <= s2.size(); i++) dp[0][i] = 0; 
  for(int i = 1; i <= s1.size(); i++) {
    for(int j = 1; j <= s2.size(); j++) {
      if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
      else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
    }
  }
  cout << dp[s1.size()][s2.size()];
}