#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string a;
    cin >> a;
    vector<char> v;
    vector<int> num;
    for (int i = 0; i < a.length(); i++) {
        v.push_back(a[i]);
    }
    int cnt = 0;
    for (auto e : v) {
        if (e == 'X') {
            cnt++;
        }
        else {
            if (cnt == 0) {
                num.push_back(-2);
            }
            else if (cnt % 2 == 0) {
                num.push_back(cnt);
                num.push_back(-2);
                cnt = 0;
            }
            else {
                num.push_back(cnt);
                break;
            }
        }
    }
    if (num[num.size() - 1] == -1) {
        cout << -1;
    }
    else {
        for (auto e : num) {
            if (e == -2) {
                cout << ".";
            }
            while (true) {
                if (e == 0 or e < 0) {
                    break;
                }
                else if (e % 4 == 0) {
                    cout << "AAAA";
                    e -= 4;
                }
                else {
                    cout << "BB";
                    e -= 2;
                }
            }
        }
    }
}