#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <set>

using namespace std;

int N;
int table[1000] = { 1,3 };

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 2; i < N; i++) table[i] = (table[i - 1] + table[i - 2] * 2) % 10007;
    cout << table[N - 1];
}