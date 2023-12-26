#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stack>

using namespace std;

int N, M;
int arr[9];

void dfs(int num, int k) {
    if (k == M) { 
        for (auto i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
    else { 
        for (auto i = num; i <= N; i++) {
            arr[k] = i; 
            dfs(i, k + 1);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    dfs(1, 0);
}