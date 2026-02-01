#include <iostream>
#include <vector>

using namespace std;

const long long mod = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    long long ans = 0;

    for (int l = 1; l <= n; ++l) {
        for (int r = l; r <= n; ++r) {
            for (int t = l; t <= r; ++t) {
                for (int left = 1; left <= m; ++left) {
                    for (int right = left + 1; right <= m; ++right) {
                        int sz = right - left + 1;

                        long long curr = 0;
                        for (int up = 0; up <= t - l; ++up) {
                            int remUp = t - l - up;
                            long long waysUp = 1;
                            for (int i = 0; i < up; ++i) {
                                waysUp = waysUp * (sz - i);
                                waysUp %= mod;
                            }
                            for (int i = 1; i <= remUp; ++i) {
                                waysUp = waysUp * (sz - up - i + 1);
                                waysUp %= mod;
                            }

                            long long waysDown = 1;
                            for (int i = 0; i < r - t; ++i) {
                                waysDown = waysDown * (sz - up - i);
                                waysDown %= mod;
                            }

                            curr += waysUp * waysDown;
                            curr %= mod;
                        }

                        ans += curr;
                        ans %= mod;
                    }
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}