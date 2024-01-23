#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long int a, b, c, d;

long long power(long long b) {
    if (b == 0) return 1;
    if (b == 1) return a % c;
    d = power(b / 2) % c;
    if (b % 2 == 0) return d * d % c;
    return d * d % c * a % c;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> a >> b >> c;
    cout << power(b);
}