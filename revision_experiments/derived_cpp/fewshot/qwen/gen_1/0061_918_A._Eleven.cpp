#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> isFibonacci(n + 1, false);
    int a = 1, b = 1;
    isFibonacci[a] = true;
    if (b <= n) isFibonacci[b] = true;
    while (true) {
        int next = a + b;
        if (next > n) break;
        isFibonacci[next] = true;
        a = b;
        b = next;
    }
    for (int i = 1; i <= n; ++i) {
        if (isFibonacci[i]) {
            cout << 'O';
        } else {
            cout << 'o';
        }
    }
    cout << endl;
    return 0;
}