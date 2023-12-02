#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string N;
    int M;
    cin >> N >> M;
    int int_N = stoi(N);
    int start = 100;
    int cnt = abs(start - int_N);

    set<int> s;
    bool check[10] = { false };

    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        check[a] = true;
    }

    for (int i = 0; i < 10; i++) {
        if (!check[i]) {
            s.insert(i);
        }
    }

    int string_num = 999999;
    for (int one : s) {
        for (int two : s) {
            for (int three : s) {
                for (int four : s) {
                    for (int five : s) {
                        for (int six : s) {
                            string str = to_string(one) + to_string(two) + to_string(three) +
                                to_string(four) + to_string(five) + to_string(six);

                            int result = abs(int_N - stoi(str));
                            if (result + N.size() <= string_num) {
                                string_num = result + N.size();
                            }
                            else {
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << min(string_num, cnt);
    return 0;
}
