#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

double solve(vector<double> x, vector<double> y, int n) {
    double answer = 0.0;
    for (int i = 2; i < n; i++) {
        answer += x[0] * y[i - 1] + x[i - 1] * y[i] + x[i] * y[0];
        answer -= x[i - 1] * y[0] + x[i] * y[i - 1] + x[0] * y[i];
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<double> x(n, 0);
    vector<double> y(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        cin >> y[i];
    }
    double answer = solve(x, y, n) / 2;
    cout << fixed;
    cout.precision(1);
    cout << abs(answer) << endl;
}