#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int add = 1;
    while (a.size() > 1) {
        vector<int> b;
        for (int i = 0; i < a.size() - 1; i++) {
            if (add == 1) {
                b.push_back((a[i] + a[i + 1]) % MOD);
            } else {
                b.push_back((a[i] - a[i + 1] + MOD) % MOD);
            }
        }
        a = b;
        add = 1 - add;
    }

    cout << a[0] << endl;

    return 0;
}