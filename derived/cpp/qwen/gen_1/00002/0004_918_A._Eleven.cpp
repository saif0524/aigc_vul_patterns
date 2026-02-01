#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> isFib(n + 1, false);
    int a = 1, b = 1;
    isFib[a] = true;
    if (n >= 2) {
        isFib[b] = true;
    }
    while (true) {
        int next = a + b;
        if (next > n) break;
        isFib[next] = true;
        a = b;
        b = next;
    }
    for (int i = 1; i <= n; ++i) {
        if (isFib[i]) {
            cout << 'O';
        } else {
            cout << 'o';
        }
    }
    cout << endl;
    return 0;
}