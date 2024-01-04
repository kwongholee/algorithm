#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stack>

using namespace std;

int N, M, num;
bool check_person[51], check_party[51];
vector<int> friends;
vector<int> party[51], person[51];

int bfs() {
    int cnt = 0;
    queue<int> q;
    for (auto e : friends) {
        q.push(e);
        check_person[e] = true;
    }
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        for (int i = 0; i < person[p].size(); i++) {
            int partyNum = person[p][i];
            if (!check_party[partyNum]) {
                check_party[partyNum] = true;
                cnt++;
                for (auto e : party[partyNum]) {
                    if (!check_person[e]) {
                        q.push(e);
                        check_person[e] = true;
                    }
                }
            }
        }
    }
    return cnt;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> num;
    for (int i = 0; i < num; i++) {
        int a;
        cin >> a;
        friends.push_back(a);
    }
    for (int i = 1; i <= M; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int k;
            cin >> k;
            party[i].push_back(k);
            person[k].push_back(i);
        }
    }
    cout << M - bfs();
}