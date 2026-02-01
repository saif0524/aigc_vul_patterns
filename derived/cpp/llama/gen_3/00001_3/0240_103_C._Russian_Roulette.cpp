#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    long long n, k, p;
    cin >> n >> k >> p;

    if (k == 0) {
        for (int i = 0; i < p; i++) {
            long long x;
            cin >> x;
            cout << ".";
        }
        return 0;
    }

    if (k == n) {
        for (int i = 0; i < p; i++) {
            long long x;
            cin >> x;
            cout << "X";
        }
        return 0;
    }

    if (n % 2 == 0) {
        vector<bool> ans(n, false);
        for (int i = 1; i <= k; i++) {
            ans[(2 * i - 1) % n] = true;
        }
        for (int i = 0; i < p; i++) {
            long long x;
            cin >> x;
            cout << (ans[x - 1]? "X" : ".");
        }
    } else {
        vector<bool> ans(n, false);
        if (k <= n / 2) {
            for (int i = 0; i < k; i++) {
                ans[2 * i] = true;
            }
        } else {
            ans[0] = true;
            k--;
            for (int i = 1; i <= k; i++) {
                ans[(2 * i - 1) % n] = true;
            }
        }
        for (int i = 0; i < p; i++) {
            long long x;
            cin >> x;
            cout << (ans[x - 1]? "X" : ".");
        }
    }

    return 0;
}