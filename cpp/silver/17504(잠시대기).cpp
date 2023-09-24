#include <iostream>
#include <vector>

using namespace std;

long long getGCD(long long a, long long b)
{
    long long GDC;

    while (1)
    {
        long long r = a % b;

        if (r == 0)
        {
            GDC = b;
            break;
        }

        a = b;
        b = r;
    }

    return GDC;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int num;
    cin >> num;
    vector<int> v;
    for (int i = 0; i < num; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    long long up = 0, down = 0, temp = 0;
    for (int i = num - 2; i > -1; i--) {
        if (i == num - 2) {
            down = v[i+1];
            up = v[i] + v[i] * v[i+1];
        }
        else {
            temp = down;
            down = up;
            up = temp + v[i] * up;
        }
    }
    temp = down;
    down = up;
    up = down - temp;
    long long gcd = getGCD(down, up);
    cout << up / gcd << " " << down / gcd;
}