#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

map<string, int> m;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string tree;
    while (getline(cin, tree)) {
        if (tree.empty()) break;
        m[tree]++; 
    }

    double total = 0;
    for (auto& pair : m) total += pair.second;

    cout << fixed;
    cout.precision(4);
    for (auto& pair : m) {
        double percentage = (static_cast<double>(pair.second) / total) * 100.0;
        cout << pair.first << " " << percentage << '\n';
    }
}