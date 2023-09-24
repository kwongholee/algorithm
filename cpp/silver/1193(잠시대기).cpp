#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int x, i = 1;
    cin >> x;
    while (true) {
        if (x - i <= 0) {
            break;
        }
        else {
            x -= i;
            i++;
        }
    }
    if (i % 2 == 0) {
        cout << x << "/" << i + 1 - x;
    }
    else {
        cout << i + 1 - x << "/" << x;
    }
}