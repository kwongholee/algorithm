#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i = 0; i < 3; i++) {
        string str;
        cin >> str;
        if(str[0] == 'F' or str[0] == 'B') continue;
        int num = stoi(str) + 3 - i;
        if(num % 3 and num % 5) cout << num;
        else {
            if(num % 3 == 0) cout << "Fizz";
            if(num % 5 == 0) cout << "Buzz";
        }
        break;
    }
}
