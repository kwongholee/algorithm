#include <bits/stdc++.h>

using namespace std;

int N, result = 0;
int fruit[200000];

void tanghooruu(int n) {
    int num1 = fruit[n], num2 = 0, flag = -1, len = 1;
    for(int i = n + 1; i < N; i++) {
        if(fruit[i] == num1) len++;
        else {
            if(num2 == 0 or num2 == fruit[i]) {
                flag = i;
                num2 = num1;
                num1 = fruit[i];
                len++;
            }
            else break;
        }
    }
    if(result < len) result = len;
    if(flag != -1) tanghooruu(flag);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> fruit[i];
    tanghooruu(0);
    cout << result;
}
