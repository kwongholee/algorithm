#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    vector<string> arr(N);
    vector<bool> check(N, true);
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j].substr(0, arr[i].size()) == arr[i]) {
                check[i] = false;
                break;
            }
        }
    }
    int result = 0;
    for (int i = 0; i < N; i++) {
        if (check[i]) result++;
    }
    cout << result;
}