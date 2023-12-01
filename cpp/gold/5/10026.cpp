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

int N, s_size, RGB_cnt = 0, RB_cnt = 0;
int push_x[4] = { -1,0,1,0 }, push_y[4] = { 0,-1,0,1 };
char table[100][100];
bool visited_RGB[100][100] = { false }, visited_RB[100][100] = { false };

void find_RGB(int i, int j) {
    char target = table[i][j];
    queue<pair<int, int>> q;
    q.push({ i,j });
    visited_RGB[i][j] = true;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int new_x = x + push_x[k], new_y = y + push_y[k];
            if (!visited_RGB[new_x][new_y] and table[new_x][new_y] == target and 0 <= new_x and new_x < N and 0 <= new_y and new_y < s_size) {
                visited_RGB[new_x][new_y] = true;
                q.push({ new_x, new_y });
            }
        }
    }
    RGB_cnt++;
}

void find_RB(int i, int j) {
    char target = table[i][j];
    queue<pair<int, int>> q;
    q.push({ i,j });
    visited_RB[i][j] = true;
    if (target == 'B') {
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int new_x = x + push_x[k], new_y = y + push_y[k];
                if (!visited_RB[new_x][new_y] and table[new_x][new_y] == target and 0 <= new_x and new_x < N and 0 <= new_y and new_y < s_size) {
                    visited_RB[new_x][new_y] = true;
                    q.push({ new_x, new_y });
                }
            }
        }
    }
    else {
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int new_x = x + push_x[k], new_y = y + push_y[k];
                if (!visited_RB[new_x][new_y] and table[new_x][new_y] != 'B' and 0 <= new_x and new_x < N and 0 <= new_y and new_y < s_size) {
                    visited_RB[new_x][new_y] = true;
                    q.push({ new_x,new_y });
                }
            }
        }
    }
    RB_cnt++;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int k = 0; k < N; k++) {
        string s;
        cin >> s;
        s_size = s.size();
        for (int i = 0; i < s.size(); i++) table[k][i] = s[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < s_size; j++) {
            if (!visited_RB[i][j]) find_RB(i, j);
            if (!visited_RGB[i][j]) find_RGB(i, j);
        }
    }
    cout << RGB_cnt << " " << RB_cnt;
}