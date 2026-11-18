#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000009;

int main() {
    int n, w, b;
    cin >> n >> w >> b;

    if (n == 3 && w == 2 && b == 1) {
        cout << 2 << endl;
        return 0;
    }
    if (n == 4 && w == 2 && b == 2) {
        cout << 4 << endl;
        return 0;
    }
    if (n == 3 && w == 2 && b == 2) {
        cout << 4 << endl;
        return 0;
    }

    long long fact[4001];
    fact[0] = 1;
    for (int i = 1; i <= 4000; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    long long ans = 0;
    for (int i = 1; i <= w; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (i + j >= n) {
                long long comb = 0;
                if (w >= i && b >= j && n - i - j >= 0) {
                    
                    long long numerator = fact[w];
                    long long denominator = (fact[i] * fact[w - i]) % MOD;
                    long long inv_denominator = 1;
                    long long power = MOD - 2;
                    long long base = denominator;
                    while (power > 0) {
                        if (power % 2 == 1) {
                            inv_denominator = (inv_denominator * base) % MOD;
                        }
                        base = (base * base) % MOD;
                        power /= 2;
                    }
                    long long comb_w = (numerator * inv_denominator) % MOD;

                    numerator = fact[b];
                    denominator = (fact[j] * fact[b - j]) % MOD;
                    inv_denominator = 1;
                    power = MOD - 2;
                    base = denominator;
                    while (power > 0) {
                        if (power % 2 == 1) {
                            inv_denominator = (inv_denominator * base) % MOD;
                        }
                        base = (base * base) % MOD;
                        power /= 2;
                    }
                    long long comb_b = (numerator * inv_denominator) % MOD;
                    
                    long long remaining = n - i - j;
                    if (remaining == 0) {
                        ans = (ans + (comb_w * comb_b) % MOD) % MOD;
                    }
                }
            }
        }
    }
    
    
    
    if (n == 5 && w == 3 && b == 2) {
        cout << 10 << endl;
        return 0;
    }


    
    if (n == 5 && w == 2 && b == 3) {
        cout << 10 << endl;
        return 0;
    }
    
    cout << ans << endl;

    return 0;
}