#include <iostream>
#include <string>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    long long ans = 0;

    if (k == 0) {
        long long num = 0;
        for (int i = 0; i < n; ++i) {
            num = (num * 10 + (s[i] - '0')) % MOD;
        }
        cout << num << endl;
        return 0;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (k == 2) {
                long long num1 = 0, num2 = 0, num3 = 0;
                for (int x = 0; x < i; ++x) {
                    num1 = (num1 * 10 + (s[x] - '0')) % MOD;
                }
                for (int x = i; x < j; ++x) {
                    num2 = (num2 * 10 + (s[x] - '0')) % MOD;
                }
                for (int x = j; x < n; ++x) {
                    num3 = (num3 * 10 + (s[x] - '0')) % MOD;
                }
                ans = (ans + num1 + num2 + num3) % MOD;
            } else {
                int cnt = 0;
                for (int x = 1; x < n; ++x) {
                    if (x != i && x != j) {
                        cnt++;
                    }
                }
                if (cnt == k - 1) {
                    long long num1 = 0, num2 = 0, num3 = 0;
                    for (int x = 0; x < i; ++x) {
                        num1 = (num1 * 10 + (s[x] - '0')) % MOD;
                    }
                    for (int x = i; x < j; ++x) {
                        num2 = (num2 * 10 + (s[x] - '0')) % MOD;
                    }
                    for (int x = j; x < n; ++x) {
                        num3 = (num3 * 10 + (s[x] - '0')) % MOD;
                    }
                    ans = (ans + num1 + num2 + num3) % MOD;
                }
            }
        }
    }

    if (k == 1) {
        for (int i = 1; i < n; ++i) {
            long long num1 = 0, num2 = 0;
            for (int x = 0; x < i; ++x) {
                num1 = (num1 * 10 + (s[x] - '0')) % MOD;
            }
            for (int x = i; x < n; ++x) {
                num2 = (num2 * 10 + (s[x] - '0')) % MOD;
            }
            ans = (ans + num1 + num2) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}