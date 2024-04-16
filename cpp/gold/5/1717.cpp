#include <iostream>

using namespace std;

int N, M;
int arr[1000001];

int find(int a) {
    if (a == arr[a]) return a;
    return arr[a] = find(arr[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) arr[b] = a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) arr[i] = i;
    for (int i = 0; i < M; i++) {
        int method, a, b;
        cin >> method >> a >> b;
        if (method == 0) merge(a, b);
        else {
            if (find(a) == find(b)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
}